#include "game.h"
#include "SDL.h"
#include <chrono>
#include <iostream>

Game::Game(std::size_t grid_width, std::size_t grid_height, float InitSpeed)
    : snake(grid_width, grid_height, InitSpeed), engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  bool paused = false;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, paused, snake);
    if (paused) {
      renderer.Pause();
    } else {
      Update();
      renderer.Render(snake, food, special_food_active);

      frame_end = SDL_GetTicks();

      // Keep track of how long each loop through the input/update/render cycle
      // takes.
      frame_count++;
      frame_duration = frame_end - frame_start;

      // After every second, update the window title.
      if (frame_end - title_timestamp >= 1000) {
        renderer.UpdateWindowTitle(score, frame_count);
        frame_count = 0;
        title_timestamp = frame_end;
      }

      // If the time for this frame is too small (i.e. frame_duration is
      // smaller than the target ms_per_frame), delay the loop to
      // achieve the correct frame rate.
      if (frame_duration < target_frame_duration) {
        SDL_Delay(target_frame_duration - frame_duration);
      }
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive)
    return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {

    if (special_food_active) {
      score += 5; // Get five points
    } else {
      score++;
    }

    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;

    // Check if special food needs to be activated
    if (!special_food_active) {
      // Randomly determine if special food should be generated
      std::random_device rd;
      std::mt19937 gen(rd());
      std::uniform_real_distribution<> dis(0.0, 1.0);
      if (dis(gen) < 0.5) { // 10% chance for special food generation
        special_food_active = true;
        special_food_start_time = std::chrono::steady_clock::now();
        snake.speed += 0.4;
      }
    }

    // Check if special food duration has elapsed
    if (special_food_active) {
      auto current_time = std::chrono::steady_clock::now();
      auto elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(
          current_time - special_food_start_time);
      if (elapsed_time >= special_food_duration) {
        special_food_active = false; // Disable special food
        snake.speed -= 0.4;
      }
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }
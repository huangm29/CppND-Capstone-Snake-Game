#include "controller.h"
#include "game.h"
#include "gameinfo.h"
#include "renderer.h"
#include <iostream>

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Gameinfo gameinfo;
  int Level = gameinfo.GetLevel();
  float InitSpeed = 0.1f * (Level + 1);
  Game game(kGridWidth, kGridHeight, InitSpeed);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  gameinfo.SetScore(game.GetScore());
  gameinfo.SetSize(game.GetSize());
  gameinfo.SaveToFile("../Savdata/Record.dat");
  return 0;
}
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "game.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake) const;
  bool Paused() const;
  void SetPause();

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
  bool _isPaused = false;
};

#endif
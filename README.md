# CPPND: Capstone Snake Game Example

This is a Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). 

<img src="snake_game.gif"/>

In this project I added several features for the Snake game.

## New Features
* **Pause**
  * The game can be paused by pressing the `p` button.

* **Entering Name**
  * The game will ask you to enter your name in the beginning.

* **Adjust Difficulty**
  * The game will ask you to choose difficulty in the beginning, which affects the initial speed of the snake.

* **Special food**
  * A special food can sometimes be generated, which is color-coded by red. The special food bonuses for extra points
    , but the snake is also significantly accelerated.

* **Saving Record**
  * The gaming record is automatically saved in `Record.dat`


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Points
### Loops, Functions, I/O
  * The project demonstrates an understanding of C++ functions and control structures.
    * Control structures are used for generating speical food. 
  * Classes use appropriate access specifiers for class members.
    * The record of game is saved to `record.dat` 
  * The project accepts user input and processes the input.
    * The game asks for player's name and difficulty.
### Object Oriented Programming
  * The project uses Object Oriented Programming techniques.
    * The gameinfo class is for saving game record.
  * Classes use appropriate access specifiers for class members.
  * Class constructors utilize member initialization lists.
  * Classes abstract implementation details from their interfaces.
    * Code is documented.
### Memory Management
  * The project uses smart pointers instead of raw pointers.
    * A smart pointer is used to get time/date. 


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

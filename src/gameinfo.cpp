#include "gameinfo.h"

Gameinfo::Gameinfo() {
  // Constructor that prompts user for name and level
  InputUserName();
  InputUserLevel();
}

Gameinfo::Gameinfo(std::string name, int level, int score, int size)
    : _name(name), _level(level), _score(score), _size(size) {
  // Constructor that initializes the object with provided values
}

void Gameinfo::SetName(std::string name) {
  // Setter function for modifying the player's name
  _name = name;
}

void Gameinfo::SetLevel(int level) {
  // Setter function for modifying the game difficulty level
  _level = level;
}

void Gameinfo::SetScore(int score) {
  // Setter function for modifying the player's score
  _score = score;
}

void Gameinfo::SetSize(int size) {
  // Setter function for modifying the game size
  _size = size;
}

void Gameinfo::InputUserName() {
  // Function to prompt the user to enter the player's name
  std::cout << "Enter player name: ";
  std::cin >> _name;
}

void Gameinfo::InputUserLevel() {
  // Function to prompt the user to enter the game difficulty level
  std::cout << "Enter game difficulty (0-5): ";
  std::cin >> _level;
}

std::string Gameinfo::GetName() {
  // Getter function to retrieve the player's name
  return _name;
}

int Gameinfo::GetLevel() {
  // Getter function to retrieve the game difficulty level
  return _level;
}

int Gameinfo::GetScore() {
  // Getter function to retrieve the player's score
  return _score;
}

int Gameinfo::GetSize() {
  // Getter function to retrieve the game size
  return _size;
}

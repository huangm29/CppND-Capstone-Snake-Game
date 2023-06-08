#ifndef GAMEINFO_H
#define GAMEINFO_H

#include <iostream>
#include <string>

class Gameinfo {
private:
  std::string _name; // Player's name
  int _level;        // Game difficulty level
  int _score;        // Player's score
  int _size;         // Game size

public:
  // Constructors
  Gameinfo();

  // Setter functions
  void SetName(std::string name);
  void SetLevel(int level);
  void SetScore(int score);
  void SetSize(int size);

  // Input functions
  void InputUserName();
  void InputUserLevel();

  // Getter functions
  std::string GetName();
  int GetLevel();
  int GetScore();
  int GetSize();

  // Save Record
  void SaveToFile(std::string filename);
};

#endif // GAMEINFO_H
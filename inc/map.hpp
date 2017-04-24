#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <string>

class Map{
private:
  char array[20][50];

public:
  // Constructor method
  Map();

  // Method to store map.txt into an array
  void importMap();

  // Method to get a specifc character at position x and y
  char getCharacter(int posx, int posy);
  void setCharacter(char sprite, int posx, int posy);

};
#endif

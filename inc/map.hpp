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
  //Method to store map.txt into an array
  void importMap();

  //Method to get map to use in Draw class

  char getCharacter(int posx, int posy);
  void getMap();
  void drawPlayer(char sprite, int posx, int posy);
  void getMapArray();
};
#endif

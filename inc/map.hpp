#ifndef MAP_HPP
#define MAP_HPP
#include <ncurses.h>

class Map{
  int map_size; // define the size of the map (counting the white spaces)
  char * array = new char[map_size]; // allocating an array to store the data from map.txt
  int position;

public:
  // Constructor method
  Map();

  //Set and Get Methods
  void setPosition(int position);
  int getPosition();

  void setMapSize(int map_size);
  int getMapSize();

  //Method to store map.txt into an array
  void importMap();

  //Method to get map to use in Draw class
  char* getMap();
};
#endif

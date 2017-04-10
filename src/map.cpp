#include "map.hpp"
#include <string>
#include <iostream> // library that contain basic input/output functions
#include <fstream>  // library that contains file input/output functions

using namespace std;

Map::Map(){
  setMapSize(1060);
  setPosition(0);
}

void Map::setPosition(int position){
  this->position = position;
}

int Map::getPosition(){
  return position;
}

int Map::getMapSize(){
  return map_size;
}

void Map::setMapSize(int map_size){
  this->map_size = map_size;
}

void Map::importMap(){

  ifstream inMap("/home/lucas/Documents/oo/ep1_game/doc/map.txt"); //opening the txt file map.txt

  if(inMap.is_open()) //checking if everything is ok with the file
  {
    while(!inMap.eof() && getPosition() < map_size)
    {
      inMap.get(array[getPosition()]); //reading one character from file to array
      //position++;
      setPosition((getPosition()+1));
    }
  }
  else //file could not be opened
  {
    cout << "File could not be opened." << endl;
  }
  //return 0;
}

char* Map::getMap(){
  return array;
}

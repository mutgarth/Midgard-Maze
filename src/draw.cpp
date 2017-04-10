#include "draw.hpp"
#include "map.hpp"
#include <string>
#include <iostream>

using namespace std;

void Draw::drawMap(Map mapa){
  char * array_d = mapa.getMap();
  //cout << "teste";
  array_d[mapa.getMapSize()-1] = '\0'; //placing character array terminating character
  //This loop priints the map on the screen
  for(int i = 0; array_d[i] != '\0'; i++)
  {
    cout << array_d[i];
    //printw("%s",array_d[i]);
  }
}

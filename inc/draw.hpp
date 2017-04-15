#ifndef DRAW_HPP
#define DRAW_HPP
#include "map.hpp"

class Draw{

public:
  // Constructor method
  Draw();

  // Method to draw thins on the screen
  void drawMap(Map *mapa);
  void drawPlayer(Map *mapa, char sprite, int positionX, int positionY);
};
#endif

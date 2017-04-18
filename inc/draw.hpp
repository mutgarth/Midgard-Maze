#ifndef DRAW_HPP
#define DRAW_HPP
#include "map.hpp"

class Draw{

public:
  // Constructor method
  Draw();

  // Methods to draw things on the screen
  void drawMap(Map *mapa);
  void drawPlayer(Map *mapa, char sprite, int positionX, int positionY);
  void drawTrap(Map *mapa, char sprite, int positionX, int positionY);
  void drawBonus(Map *mapa, char sprite, int positionX, int positionY);
};
#endif

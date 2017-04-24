#ifndef DRAW_HPP
#define DRAW_HPP
#include "map.hpp"
#include "player.hpp"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Draw{

public:
  // Constructor method
  Draw();

  // Methods to draw things on the screen
  void drawMap(Map *mapa);
  void drawPlayer(Map *mapa, char sprite, int positionX, int positionY);
  void drawTrap(Map *mapa, char sprite, int positionX, int positionY);
  void drawBonus(Map *mapa, char sprite, int positionX, int positionY);
  void drawStatus(Player *player, int SCORE_COND);
  void drawPresentation(int SCORE_COND);
  void drawRank();
  void drawInitialMenu();
  void drawFinalMenu(Player *player);

};
#endif

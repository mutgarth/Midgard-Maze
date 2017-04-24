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
  void drawMap(Map *mapa);  // Draw the map
  void drawPlayer(Map *mapa, char sprite, int positionX, int positionY); // Draw the player on map
  void drawTrap(Map *mapa, char sprite, int positionX, int positionY);   // Draw traps on map
  void drawBonus(Map *mapa, char sprite, int positionX, int positionY);  // Draw bonus on map
  void drawStatus(Player *player, int SCORE_COND);  //Draw status on the screen (Life and Score)
  void drawPresentation(int SCORE_COND);  // Draw just a menssage about the game
  void drawRank();  // Draw the rank from rank.txt
  void drawInitialMenu(); // Draw the firt menu on the screen
  void drawFinalMenu(Player *player); // Draw the final menu on the screen.

};
#endif

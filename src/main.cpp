#include "draw.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>


using namespace std;

int main(int argc, char** argv) {

  initscr();
  noecho();

  //Instance objects
  Draw * draw = new Draw();
  Map * mapa = new Map();
  Player  * player = new Player();
  Trap * trap_1 = new Trap();

  mapa->importMap();
  draw->drawTrap(mapa, trap_1->getSprite(), trap_1->getPositionX(), trap_1->getPositionY());

  draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());
  draw->drawMap(mapa);

  // Infinite Loop
    while(1){

      mapa->importMap();
      player->movePlayer(mapa);
      Trap * trap_1 = new Trap();

      draw->drawTrap(mapa, trap_1->getSprite(), trap_1->getPositionX(), trap_1->getPositionY());
      draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

      trap_1->~Trap();
      refresh();
      clear();
      draw->drawMap(mapa);

  }

  endwin();

  return 0;
}

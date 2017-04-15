#include "draw.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include "map.hpp"
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
  Player  * player = new Player();
  Map * mapa = new Map();


  mapa->importMap();
  draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());
  draw->drawMap(mapa);

  // Infinite Loop
    while(1){

      mapa->importMap();
      player->movePlayer(mapa);
      draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

      refresh();
      clear();
      draw->drawMap(mapa);

  }

  endwin();

  return 0;
}

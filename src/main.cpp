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

  Player  * player = new Player();
  Map * mapa = new Map();
  mapa->importMap();
  mapa->drawPlayer(player->getSprite(), player->getPositionX(), player->getPositionY());
  mapa->getMap();

    while(1){

      mapa->importMap();
      player->movePlayer(mapa);
      mapa->drawPlayer(player->getSprite(), player->getPositionX(), player->getPositionY());

      refresh();
      clear();
      mapa->getMap();


  }

  endwin();

  return 0;
}

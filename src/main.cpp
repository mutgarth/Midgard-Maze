#include "draw.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include "map.hpp"
#include <iostream>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>


using namespace std;

int main(int argc, char** argv) {
  initscr();
  noecho();

  Player player_1;
  Map mapa_1;
  mapa_1.importMap();
  Draw draw;
  draw.drawMap(mapa_1);
  //
  // while(1){
  //   player_1.movePlayer();
  //   refresh();
  // }
  endwin();
  return 0;
}

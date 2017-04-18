#include "draw.hpp"
#include "gameobject.hpp"
#include "player.hpp"
#include "map.hpp"
#include "trap.hpp"
#include "bonus.hpp"
#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include <stdlib.h>


using namespace std;

int main(int argc, char** argv) {

  srand(time(NULL));
  initscr();
  noecho();

  //Instancing objects
  Draw * draw = new Draw();
  Map * mapa = new Map();
  Player  * player = new Player();

  // Numbers of bonus in game
  int NUM_BON = 5;
  Bonus * bonus_list[NUM_BON];
  // Numbers of traps in game
  int NUM_TRAP = 5;
  Trap * trap_list[NUM_TRAP];

  for(int i=0; i<NUM_BON;i++){
    bonus_list[i] = new Bonus();
  }

  // Using methods
  mapa->importMap();

  draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

  draw->drawMap(mapa);

  printw("\n");
  printw("Press any key to start...");


  // Infinite Loop
    while(1){

      // Import Map
      mapa->importMap();
      // Getch character to move player
      player->movePlayer(mapa);

      // Drawing traps on the mapa and resolving the colisions
      for(int i=0; i<NUM_TRAP; i++){
        trap_list[i] = new Trap();
        draw->drawTrap(mapa, trap_list[i]->getSprite(), trap_list[i]->getPositionX(), trap_list[i]->getPositionY());

        if(player->getPositionX() == trap_list[i]->getPositionX() && player->getPositionY() == trap_list[i]->getPositionY()){
          player->setLife(player->getLife() - 30);
        }
      }

      // Drawing bonus on the mapa and resolving the colisions
      for(int i=0; i<NUM_BON; i++){
        draw->drawBonus(mapa, bonus_list[i]->getSprite(), bonus_list[i]->getPositionX(), bonus_list[i]->getPositionY());

        if(player->getPositionX() == bonus_list[i]->getPositionX() && player->getPositionY() == bonus_list[i]->getPositionY()){
          player->setLife(player->getLife() + 10);
          bonus_list[i]->~Bonus();
          bonus_list[i] = new Bonus();
        }
      }

      // The last element to draw is player
      draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

      refresh();
      clear();

      // Redraw the map
      draw->drawMap(mapa);

      // Player Status
      printw("\n");
      printw("Health Points: %d", player->getLife());

  }

  endwin();
  return 0;
}

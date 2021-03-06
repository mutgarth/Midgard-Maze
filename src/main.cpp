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
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

  int NUM_BON = 8;        // Bonus quantity in the game
  int NUM_TRAP = 15;      // Trap quantity in the game
  int BON_TO_SCORE = 20;  // How many score points are given by bonus
  int BON_LIFE = 10;      // How many health points are given by bonus
  int TRAP_DAMAGE = 20;   // How many health points player looses due traps
  int SCORE_COND = 100;     // Score Points Condition

  // Instantiating objects ----------------------------------------------------------------
  Map * mapa = new Map();
  Player  * player = new Player();
  Draw * draw = new Draw();
  draw->drawInitialMenu(); // Drawing the initial menu

  srand(time(NULL)); // Generate real random positions for the elements

  initscr();
  noecho();

  // List to instantiate N traps and bonus -------------------------------------------------
  Bonus * bonus_list[NUM_BON];
  Trap * trap_list[NUM_TRAP];

  // Instantiating bonus and trap lists ----------------------------------------------------
  for(int i=0; i<NUM_BON;i++){
    bonus_list[i] = new Bonus();
  }

  for(int i=0; i<NUM_TRAP;i++){
    trap_list[i] = new Trap();
  }


  // Using methods ---------------------------------------------------------------------------
  mapa->importMap();

  draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

  draw->drawMap(mapa);

  draw->drawPresentation(SCORE_COND);

  // Infinite Loop ----------------------------------------------------------------------------
    while(player->getWinner()==FALSE && player->getAlive()==TRUE){

      mapa->importMap();
      player->movePlayer(mapa);
      player->WinOrDeath(mapa, SCORE_COND); // Win or Loose conditions

      // Drawing traps on the mapa and resolving colisions
      for(int i=0; i<NUM_TRAP; i++){
        trap_list[i]->moveTrap(mapa);
        draw->drawTrap(mapa, trap_list[i]->getSprite(), trap_list[i]->getPositionX(), trap_list[i]->getPositionY());
        player->trapColision(trap_list[i],TRAP_DAMAGE); // Verify if player position is equal to trap position
  }

      // Drawing bonus on the map and resolving colisions
      for(int i=0; i<NUM_BON; i++){
        bonus_list[i]->moveBonus(mapa);
        draw->drawBonus(mapa, bonus_list[i]->getSprite(), bonus_list[i]->getPositionX(), bonus_list[i]->getPositionY());
        player->bonusColision(bonus_list[i], BON_LIFE, BON_TO_SCORE);   // Verify if player position is equal to bonus position
      }

      // Drawing player
      draw->drawPlayer(mapa, player->getSprite(), player->getPositionX(), player->getPositionY());

      refresh();
      clear();

      draw->drawMap(mapa);                        // Redrawing the map
      draw->drawStatus(player, SCORE_COND);       // Player Status
    }
  endwin();

  if(player->getAlive()==FALSE){
    return 0;
  }
  draw->drawFinalMenu(player);
  return 0;
}

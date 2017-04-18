#include "draw.hpp"
#include "map.hpp"
#include <string>
#include <iostream>
#include <ncurses.h>

using namespace std;

Draw::Draw(){}

void Draw::drawMap(Map *mapa){
    for(int i = 0; i < 20; i++){
      for(int u = 0; u < 50; u++){
        printw("%c", mapa->getCharacter(i,u));
        if(u >= 49){
          printw("\n");
        }
    }
  }
}

void Draw::drawPlayer(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}

void Draw::drawTrap(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}

void Draw::drawBonus(Map *mapa, char sprite, int posx, int posy){
  mapa->setCharacter(sprite, posx, posy);
}

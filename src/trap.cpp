#include "trap.hpp"
#include "gameobject.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Trap::Trap(){
  setSprite('O');
  setPositionX(rand() % 50);
  setPositionY(rand() % 20);
}

Trap::~Trap(){}

void Trap::moveTrap(Map *mapa){

    setPositionX(rand() % 50);
    setPositionY(rand() % 20);

  while (mapa->getCharacter(getPositionY(),getPositionX()) == '='
        || mapa->getCharacter(getPositionY(),getPositionX()) == '8'){
    setPositionX(rand() % 50);
    setPositionY(rand() % 20);
  }
}

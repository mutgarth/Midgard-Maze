#include "bonus.hpp"
#include "gameobject.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Bonus::Bonus(){
  setSprite('&');
  setPositionX(rand() % 50);
  setPositionY(rand() % 20);
}

// Destructor Method.
Bonus::~Bonus(){
  setSprite('-');
}

void Bonus::moveBonus(Map *mapa){
  if (mapa->getCharacter(getPositionY(),getPositionX()) == '=' ){
    setPositionX(rand() % 50);
    setPositionY(rand() % 20);
  }
}

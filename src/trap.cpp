#include "trap.hpp"
#include "gameobject.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

Trap::Trap(){
  srand(time(NULL));
  setSprite('O');
  setPositionX(rand() % 50);
  setPositionY(rand() % 20);
}

Trap::~Trap(){}

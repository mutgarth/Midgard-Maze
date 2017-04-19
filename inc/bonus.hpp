#ifndef BONUS_HPP
#define BONUS_HPP
#include "gameobject.hpp"
#include "map.hpp"
#include <ncurses.h>
#include <unistd.h>


class Bonus : public GameObject{

public:
  Bonus();
  ~Bonus();

// Method to move out bonus from wall 
void moveBonus(Map *mapa);

};

#endif

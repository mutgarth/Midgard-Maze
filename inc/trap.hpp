#ifndef TRAP_HPP
#define TRAP_HPP
#include "gameobject.hpp"
#include "map.hpp"
#include <ncurses.h>
#include <unistd.h>


class Trap : public GameObject{

public:
  Trap();
  ~Trap();

  // This method will move the trap when traps are created in wall location
  void moveTrap(Map *mapa);
};

#endif

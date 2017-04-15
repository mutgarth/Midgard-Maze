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

};

#endif

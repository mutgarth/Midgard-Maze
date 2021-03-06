#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "gameobject.hpp"
#include "map.hpp"
#include "trap.hpp"
#include "bonus.hpp"
#include <ncurses.h>
#include <unistd.h>


class Player : public GameObject{

bool alive;
int score;
int life;
bool winner;

public:

  //Constructor Methods
  Player();
  ~Player();


  //Set and Get Methods
  void setLife(int life);
  int getLife();

   void setAlive(bool alive);
   bool getAlive();

   void setScore(int score);
   int getScore();

   void setWinner(bool winner);
   bool getWinner();

  //Method to move player
  void movePlayer(Map *mapa);

  // Method to verify if the player won or died
  void WinOrDeath(Map *mapa, int SCORE_COND);

  //Method to resolve colisions between player and traps
  void trapColision(Trap *trap, int TRAP_DAMAGE);

  //Method to resolve colisions between player and bonus
  void bonusColision(Bonus *bonus, int BON_LIFE, int BON_TO_SCORE);

};

#endif

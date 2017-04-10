#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "gameobject.hpp"
#include <ncurses.h>
#include <unistd.h>


class Player : public GameObject{

bool alive;
int score;
int life;
bool winner;
int next_positionX;
int next_positionY;

public:

  //Constructor Methods
  Player();
  ~Player();


  //Set and Get Methods
  void setNextPositionX(int next_positionX);
  int getNextPositionX();

  void setNextPositionY(int next_positionY);
  int getNextPositionY();

  void setLife(int life);
  int getLife();

   void setAlive(bool alive);
   bool getAlive();

   void setScore(int score);
   int getScore();

   void setWinner(bool winner);
   bool getWinner();

  //Method to move player
  void movePlayer();


};

#endif

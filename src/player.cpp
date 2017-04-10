#include "player.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>

int direction = 1;

Player::Player(){
  setSprite("@");
  setPositionX(0);
  setPositionY(0);
  setNextPositionX(0);
  setNextPositionY(0);
  setLife(100);
}

Player::~Player(){};

void Player::setLife(int life){
  this->life = life;
}

int Player::getLife(){
  return life;
}

void Player::setNextPositionX(int next_positionX){
  this->next_positionX = next_positionX;
}

void Player::setNextPositionY(int next_positionY){
  this->next_positionY = next_positionY;
}

int Player::getNextPositionX(){
  return next_positionX;
}

int Player::getNextPositionY(){
  return next_positionY;
}

void Player::movePlayer(){

   while(getch() == 'd'){
     refresh();
     clear();
     mvprintw(getPositionY(), getPositionX(), getSprite());
     setNextPositionX((getPositionX() + direction));
     setPositionX(getNextPositionX());
     if(getNextPositionX() >= 51) {
       setPositionX((getPositionX() - direction));
     }
   }

   while(getch() == 'a'){
     refresh();
     clear();
     mvprintw(getPositionY(), getPositionX(), getSprite());
     //next_positionX() = getPositionX() - direction;
     //setPositionX()= next_positionX();
     setNextPositionX((getPositionX() - direction));
     setPositionX(getNextPositionX());
     if(getNextPositionX() < 0) {
       setPositionX((getPositionX() + direction));
     }

   }

   while(getch() == 's'){
     refresh();
     clear();
     mvprintw(getPositionY(), getPositionX(), getSprite());
     //next_positionY() = getPositionY() + direction;
     //setPositionY()= next_positionY();
     setNextPositionY((getPositionY() + direction));
     setPositionY(getNextPositionY());
   }

   while(getch() == 'w'){
     refresh();
     clear();
     mvprintw(getPositionY(), getPositionX(), getSprite());
     //next_positionY() = getPositionY() + direction;
     //setPositionY()= next_positionY();
     setNextPositionY((getPositionY() - direction));
     setPositionY(getNextPositionY());
   }
}

void Player::setAlive(bool alive){
  this->alive = alive;
}

bool Player::getAlive(){
  return alive;
}

void Player::setScore(int score){
  this->score = score;
}

int Player::getScore(){
  return score;
}

void Player::setWinner(bool wineer){
  this->winner = winner;
}

bool Player::getWinner(){
  return winner;
}

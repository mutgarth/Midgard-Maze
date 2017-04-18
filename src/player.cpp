#include "player.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>

// Constructor method
Player::Player(){
  setSprite('@');
  setPositionX(1);
  setPositionY(1);
  setLife(100);
}


Player::~Player(){};


void Player::setLife(int life){
  this->life = life;
}

int Player::getLife(){
  return life;
}

// Method to move the player through map
void Player::movePlayer(Map *mapa){

  char key;
  key = getch();

  if(key == 'w'){
    if(mapa->getCharacter(getPositionY()-1,getPositionX()) == '='){
      setPositionY(getPositionY());
    } else {
  		  this->setPositionY(getPositionY()-1);
      }

    } else if (key == 's'){
      if(mapa->getCharacter(getPositionY()+1,getPositionX()) == '='){
        setPositionY(getPositionY());
      } else {
    		  this->setPositionY(getPositionY()+1);
        }


	} else if (key == 'a'){
    if(mapa->getCharacter(getPositionY(),getPositionX()-1) == '='){
      setPositionX(getPositionX());
    } else {
  		  this->setPositionX(getPositionX()-1);
      }


  } else if (key == 'd'){
    if(mapa->getCharacter(getPositionY(),getPositionX()+1) == '='){
      setPositionX(getPositionX());
    } else {
  		  this->setPositionX(getPositionX()+1);
      }
  }
}

// Method to set player status
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

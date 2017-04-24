#include "player.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

// Constructor method
Player::Player(){
  setSprite('@');
  setPositionX(1);
  setPositionY(1);
  setLife(100);
  setWinner(FALSE);
  setAlive(TRUE);
  setScore(0);
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

void Player::setWinner(bool winner){
  this->winner = winner;
}

bool Player::getWinner(){
  return winner;
}

void Player::WinOrDeath(Map *mapa, int SCORE_COND){

  if(mapa->getCharacter(getPositionY(),getPositionX()) == '8' && getScore() >= SCORE_COND){
    setWinner(TRUE);
  }

  // If the player dies, the follow menssage will be printed
  if(getLife()<=0){
    system("clear");
    printf("\n");
    printf(" -------- WELCOME TO VALHALLA ---------- ");
    getchar();
    sleep(3);
    setAlive(FALSE);
  }
}

void Player::trapColision(Trap *trap, int TRAP_DAMAGE){
  // Verify if player position is equal to trap position
    if(getPositionX() == trap->getPositionX() && getPositionY() == trap->getPositionY()){
      setLife(getLife() - TRAP_DAMAGE);
    }
}

void Player::bonusColision(Bonus *bonus, int BON_LIFE, int BON_TO_SCORE){
  if(getPositionX() == bonus->getPositionX() && getPositionY() == bonus->getPositionY()){
    setLife(getLife() + BON_LIFE);
    setScore(getScore() + BON_TO_SCORE);
    bonus->~Bonus();
    bonus = new Bonus();
  }
}

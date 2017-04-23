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

  if(mapa->getCharacter(getPositionY(),getPositionX()) == '8'){
    setWinner(TRUE);
  }

  if(getLife()<=0){
    setAlive(FALSE);
  }

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

void Player::WinOrDeath(int SCORE_COND){
  if (getWinner()==TRUE && getScore()>=SCORE_COND){
    clear();
    printw("\n");
    printw("You Win!");
    printw("\n");

    printw("Your Score: %d", getScore());
    printw("\n");
    printw("Enter your Name: ");

  } else if(getAlive()==FALSE){
    clear();
    printw("\n");
    printw("Welcome to Valhalla!");
    printw("\n");
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

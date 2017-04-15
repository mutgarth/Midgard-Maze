#include <iostream>
#include <ncurses.h>
#include <string>
#include "gameobject.hpp"

using namespace std;

//Methods to set and get the Position
void GameObject::setPositionX(int positionX){
  this->positionX = positionX;
}

void GameObject::setPositionY(int positionY){
  this->positionY = positionY;
}

int GameObject::getPositionY(){
  return positionY;
}

int GameObject::getPositionX(){
  return positionX;
}

//Methods to set and get the sprite
void GameObject::setSprite(char sprite){
  this->sprite = sprite;
}

char GameObject::getSprite(){
  return sprite;
}

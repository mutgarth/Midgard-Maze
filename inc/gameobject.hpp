#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP

class GameObject{
  int positionX;
  int positionY;
  char sprite;

public:
  // Métodos acessores
  void setPositionX(int positionX);
  int getPositionX();

  void setPositionY(int positionY);
  int getPositionY();

  void setSprite(char sprite);
  char getSprite();

};
#endif

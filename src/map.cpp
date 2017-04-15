#include "map.hpp"
#include <string>
#include <iostream> 
#include <fstream>
#include <string>
#include <ncurses.h>
#include <stdio_ext.h>

using namespace std;

Map::Map(){}

void Map::importMap(){

	ifstream map ("/home/lucas/Documents/oo/ep1_game/doc/map.txt");

	string aux;

	for(int i = 0; i < 20; i++){
		getline(map, aux);
		for(int u = 0; u < 50; u++){
			this->array[i][u] = aux[u];
		}
	}
	map.close();
}

  void Map::getMap(){

  		for(int i = 0; i < 20; i++){
  			for(int u = 0; u < 50; u++){
  		 		printw("%c", this->array[i][u]);
  		 		if(u >= 49){
  		 			printw("\n");
  		 		}
  		}
  	}
	}

	char Map::getCharacter(int posx, int posy){
		char c = array[posx][posy];
		return c;
	}

  void Map::drawPlayer(char sprite, int posx, int posy){
  	this->array[posy][posx] = sprite;
  }

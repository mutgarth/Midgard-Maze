#include "map.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <ncurses.h>
#include <stdio_ext.h>

using namespace std;

// Constructor method
Map::Map(){}

// Method to read map.txt into array[][]
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

// Method to get a specifc character at position x and y
char Map::getCharacter(int posx, int posy){
	return this->array[posx][posy];
}

// Method to set a sprite (player, trap or bonus) to a specifc position x and y
void Map::setCharacter(char sprite, int posx, int posy){
	this->array[posy][posx] = sprite;
}

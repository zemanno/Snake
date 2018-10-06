/// Author: Norbert Zeman
/// Date:	Thursday October 05, 2018
/// File:	GameMap.h

#pragma once
#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <iostream>
#include "Snake.h"
using namespace std;

class Snake;

class GameMap
{
	//instance of snake to acess methods
	Snake* snake;

public:
	GameMap() {};
	~GameMap() { delete[] map; };

	//Dimentions of Game World
	static const char mapWidth = 20;
	static const char mapHeight = 20;

	//Size of the map
	static const int size = mapWidth * mapHeight;

	//Tile values for the map
	int map[size];

	//Method Declarations
	void generateFood();
	void printMap();
	char getMapValue(char);
};

#endif // !GAMEMAP_H
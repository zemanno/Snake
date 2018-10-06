/// Author: Norbert Zeman
/// Date:	Thursday October 05, 2018
/// File:	Snake.h

#pragma once
#ifndef SNAKE_H
#define SNAKE_H
#include "Game.h"
#include "GameMap.h"

class GameMap;
class Game;

class Snake
{
	GameMap* GMap;

public:
	Snake(GameMap* _GMap) : GMap(_GMap) {};
	~Snake() {};
	Game* game;

	// snake head variables, and it's length
	int headPosX = 0, headPosY = 0, direction, food = 3;

	void changeDirection(char key)
	{
		/* 
		
		reference of how movement will work

		  W
		A + S
		  D

		  1
		4 + 2
		  3
		
		*/

		switch (key)
		{
			case 'w': if (direction != 2) direction = 0; break;
			case 'd': if (direction != 3) direction = 1; break;
			case 's': if (direction != 4) direction = 2; break;
			case 'a': if (direction != 5) direction = 3; break;
		}
	}

	void move(int, int);
	void initMap();
};

#endif // !SNAKE_H
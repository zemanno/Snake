#pragma once
#ifndef GAME_H
#define GAME_H
#include <conio.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "Snake.h"
#include "GameMap.h"
using namespace std;

class Snake;
class GameMap;

class Game
{
	Snake* snake;
	GameMap* GMap;
public:
	Game();
	~Game();

	void run();
	void clearScreen();
	void update();
	void printMap();
	void score();

	bool running = true;
};

#endif // !GAME_H
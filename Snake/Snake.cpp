/// Author: Norbert Zeman
/// Date:	Thursday October 05, 2018
/// File:	Snake.cpp

#include "Snake.h"

void Snake::initMap()
{
	// place initial head location in middle of map
	headPosX = GameMap::mapWidth / 2;
	headPosY = GameMap::mapHeight / 2;
	GMap->map[headPosX + headPosY * GameMap::mapWidth] = 1;

	// top and botom walls
	for (int x = 0; x < GameMap::mapWidth; x++) 
	{
		GMap->map[x] = -1;
		GMap->map[x + (GameMap::mapHeight - 1) * GameMap::mapWidth] = -1;
	}

	// left and right walls
	for (int y = 0; y < GameMap::mapHeight; y++) 
	{
		GMap->map[0 + y * GameMap::mapWidth] = -1;
		GMap->map[(GameMap::mapWidth - 1) + y * GameMap::mapWidth] = -1;
	}

	// spawn first food
	GMap->generateFood();
}


// move snake head to new location
void Snake::move(int dx, int dy)
{
	// determine new head position
	int newX = headPosX + dx;
	int newY = headPosY + dy;

	// check if there's food at current location
	if (GMap->map[newX + newY *  GameMap::mapWidth] == -2)
	{
		// increase body length
		food++;

		// generate a new piece of food on the map
		GMap->generateFood();
	}

	else if (GMap->map[newX + newY * GameMap::mapWidth] != 0)
		game->running = false;

	// finally, Move Head To New Location
	headPosX = newX;
	headPosY = newY;
	GMap->map[headPosX + headPosY * GameMap::mapWidth] = food + 1;
}
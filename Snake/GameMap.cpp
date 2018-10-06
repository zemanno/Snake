#include "GameMap.h"

//Methods used to initialise the game and print it to screen

//Print everything to console
void GameMap::printMap() 
{
	for (int x = 0; x < GameMap::mapWidth; ++x) 
	{
		for (int y = 0; y < GameMap::mapHeight; ++y) 
		{
			//Prints the value at the current x, y location
			cout << getMapValue(map[x + y * GameMap::mapWidth]);
		}
		//ends Line for current X value
		cout << endl;
	}
}

//Retuns Graphical charachter for display from map value
char GameMap::getMapValue(char value)
{
	//Returns a part of Snake body
	if (value > 0) return 'o';

	switch (value) 
	{
		//return wall
		case -1: return 'X'; break;
		//return food
		case -2: return 'O'; break;
	}
}

void GameMap::generateFood() {
	int x = 0, y = 0;

	do 
	{
		//generate random x and y values within the map
		x = rand() % (GameMap::mapWidth - 2) + 1;
		y = rand() % (GameMap::mapHeight - 2) + 1;

		//if location is not free, try again
	} while (map[x + y * GameMap::mapWidth] != 0);

	//place new food 
	map[x + y * GameMap::mapWidth] = -2;
}
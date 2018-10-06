#include "Game.h"

Game::Game()
{
	GMap = new GameMap();
	snake = new Snake(GMap);
	snake->game = this;
}

Game::~Game()
{
	delete GMap;
	delete snake;
}

void Game::run()
{
	snake->initMap();
	running = true;

	while (running) 
	{
		update();
		clearScreen();
		printMap();

		//pause for 0.5 seconds before executing the loop again
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	//prints game over text
	score();

	// Stop console from closing instantly
	cin.ignore();
}

void Game::clearScreen()
{
	//Clear the screen
	char a = 30;
	for (int i = 0; i < a; i++) 
		cout << "\n";
}

void Game::update()
{
	// If a key is pressed
	if (_kbhit()) 
	{
		// Change to direction determined by key pressed
		snake->changeDirection(_getch());
	}

	//Move in Direction indicated
	switch (snake->direction) 
	{
		case 0: snake->move(-1, 0); break;
		case 1: snake->move(0, 1);  break;
		case 2: snake->move(1, 0); break;
		case 3: snake->move(0, -1); break;
	}

	//Reduce snake values on map by 1
	for (int i = 0; i < GameMap::size; i++)
		if (GMap->map[i] > 0) 
			GMap->map[i]--;
	
}

void Game::printMap() { GMap->printMap(); }

void Game::score() 
{
	// Print out game over text
	cout << "\t\tGame over!" << endl << "\t\tYour score is: " << snake->food;
}
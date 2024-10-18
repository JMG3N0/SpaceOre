#include "Player.h"

void ScreenUpdate(int currentScreen, Player player);


int main()
{
	const int screenWidth = 1024;
	const int screenHeight = 768;
	Player player;
	setPlayer(player);
	int gameStage = 0;

	InitWindow(screenWidth, screenHeight, "SpaceOre");

	while (!WindowShouldClose())
	{
		 ScreenUpdate(gameStage, player);
	}

}
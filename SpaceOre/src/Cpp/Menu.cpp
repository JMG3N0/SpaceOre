#include "raylib.h"
#include "Player.h"



enum Screen
{
	Main = 0, Play, Credits, Quit
};

int halfScreenX = (1024 / 2);
int halfScreenY = (768 / 2);

void ScreenUpdate(int currentScreen, Player player)
{
	switch (currentScreen)
	{
	case 0:
		TitleScreen(currentScreen);
		break;
	default:
		break;
	}
}

void TitleScreen(int currentScreen)
{
	//Draw Main Menu Text
	DrawText("SpaceOre",halfScreenX, halfScreenY, 30, WHITE);
	DrawText("Play",halfScreenX, (halfScreenY + 10), 15, WHITE);
	DrawText("Credits",halfScreenX, (halfScreenY + 20), 15, WHITE);

	currentScreen = 1;
}
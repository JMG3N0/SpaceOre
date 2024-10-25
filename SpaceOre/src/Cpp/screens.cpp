#include "screens.h"

#include "player.h"

#include "raylib.h"

namespace space_ore
{
	Player player;
	Menu MenuScreen;
	
	int halfScreenX = (1024 / 2);
	int halfScreenY = (768 / 2);
	
	

	void StartGame()
	{
		const int screenWidth = 1024;
		const int screenHeight = 768;
		MenuScreen = Main;
		initializePlayer(player);

		InitWindow(screenWidth, screenHeight, "SpaceOre");

		while (!WindowShouldClose())
		{
			ScreenUpdate();
		}
		

		CloseWindow();
	}

	void GameplayLoop()
	{
		
		
		
			

		
	}

	void ScreenUpdate()
	{
		BeginDrawing();
		switch (MenuScreen)
		{
		case 0:
			TitleScreen();
			break;
		case 1:
			GameplayLoop();
			break;
		/*case 2:

			break;*/
		default:
			break;
		}
		EndDrawing();

	}


	void TitleScreen()
	{
		//Draw Main Menu Text
		DrawText("SpaceOre", halfScreenX, halfScreenY, 30, WHITE);
		DrawText("Play", halfScreenX, (halfScreenY + 30), 15, WHITE);
		DrawText("Credits", halfScreenX, (halfScreenY + 60), 15, WHITE);
		DrawText("Exit", halfScreenX, (halfScreenY + 90), 15, WHITE);

#ifdef DEBUG
		DrawRectangle(halfScreenX-20, halfScreenY+30, 10, 10, RED);
#endif // DEBUG

		

		
	}
}
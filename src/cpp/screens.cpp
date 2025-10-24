#include "screens.h"

#include "player.h"

#include "raylib.h"

namespace space_ore
{
	Player player;
	Menu MenuScreen;
	const int screenWidth = 1024;
	const int screenHeight = 768;
	int halfScreenX = (screenWidth / 2);
	int halfScreenY = (screenHeight / 2);
	
	

	void StartGame()
	{
		
		MenuScreen = Main;
	//	initializePlayer(player);
		InitWindow(screenWidth, screenHeight, "SpaceOre");
		SetExitKey(KEY_NULL);
		initializePlayer(player);

		while (!WindowShouldClose())
		{

			ScreenUpdate();
		} 
		
		UnloadTexture(player.Spaceship);
		CloseWindow();
	}

	void GameplayLoop()
	{
		
		drawPlayer(player);

		actionUpdate(player);
			

		
	}

	void ScreenUpdate()
	{
		BeginDrawing();
		ClearBackground(BLACK);
		switch (MenuScreen)
		{
		case Main:
			TitleScreen();
			break;
		case Play:
			GameplayLoop();
			break;
		case Credits:
			CreditsScreen();
			break;
		case Quit:
			UnloadTexture(player.Spaceship);
			CloseWindow();
			break;
		default:
			break;
		}
		EndDrawing();

	}


	void TitleScreen()
	{
		
#ifdef _DEBUG
		DrawRectangle(halfScreenX - 40, halfScreenY + 20, 50, 20, RED);
#endif // DEBUG

		//Draw Main Menu Text
		DrawText("SpaceOre", (halfScreenX - 75), halfScreenY - 40, 30, WHITE);
		DrawText("Play", (halfScreenX - 30), (halfScreenY + 20), 15, WHITE);
		DrawText("Credits", (halfScreenX - 30), (halfScreenY + 50), 15, WHITE);
		DrawText("Exit", (halfScreenX - 30), (halfScreenY + 80), 15, WHITE);
		DrawText("Use the mouse left click to select a option", (halfScreenX - 120), (halfScreenY + 150), 10, WHITE);


		if (GetMousePosition().x >= (halfScreenX - 40) && GetMousePosition().x <= (halfScreenX + 20))
		{
			if (GetMousePosition().y >= (halfScreenY + 10) && GetMousePosition().y <= (halfScreenY+35))
			{
				DrawText("Play", (halfScreenX - 30), (halfScreenY + 20), 15, BLUE);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					MenuScreen = Play;
				}
			}
			if (GetMousePosition().y >= (halfScreenY + 40) && GetMousePosition().y <= (halfScreenY + 65))
			{
				DrawText("Credits", (halfScreenX - 30), (halfScreenY + 50), 15, BLUE);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					MenuScreen = Credits;
				}
			}
			if (GetMousePosition().y >= (halfScreenY + 70) && GetMousePosition().y <= (halfScreenY + 95))
			{
				DrawText("Exit", (halfScreenX - 30), (halfScreenY + 80), 15, BLUE);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					MenuScreen = Quit;
				}
			}
			
		}
		

		
	}

	void CreditsScreen()
	{
#ifdef _DEBUG
		DrawRectangle(halfScreenX + 80, halfScreenY + 95, 80, 20, RED);
#endif // DEBUG

		DrawText("Game made by Joan Manuel Rivas Cepeda", (halfScreenX - 200), halfScreenY, 20, WHITE);
		DrawText("Play Game", (halfScreenX + 100), halfScreenY + 100, 10, WHITE);
		DrawText("Return to Main Menu", (halfScreenX - 120), halfScreenY + 100, 10, WHITE);

		if (GetMousePosition().y >= (halfScreenY + 90) && GetMousePosition().y <= (halfScreenY + 120))
		{
			if (GetMousePosition().x >= halfScreenX + 70 && GetMousePosition().x <= halfScreenX + 160)
			{
				DrawText("Play Game", (halfScreenX + 100), halfScreenY + 100, 10, BLUE);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					MenuScreen = Play;
				}
			}
			if (GetMousePosition().x <= halfScreenX  && GetMousePosition().x >= halfScreenX - 140)
			{
				DrawText("Return to Main Menu", (halfScreenX - 120), halfScreenY + 100, 10, BLUE);
				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
				{
					MenuScreen = Main;
				}
			}
		}

	}


}
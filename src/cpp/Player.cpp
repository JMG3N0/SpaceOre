#include "Player.h"
#include "raymath.h"


namespace space_ore
{

	int screenWidth = 1024;
	int screenHeight = 768;

	Player initializePlayer(Player& player)
	{
		player.Spaceship = LoadTexture("res/spaceship_sheet.png");
		player.maxBullets = 1;
		player.currentBullets = 1;
		player.hp = 10;
		player.score = 0;
		player.maxScore = 0;
		player.speed = 10.0f;
		player.pivot.x = 16.0f;
		player.pivot.y = 30.0f;
		player.rotation = 0.0;
		player.radius = 10.0f;
		player.pos.x = static_cast<float>(screenWidth / 2);
		player.pos.y = static_cast<float>(screenHeight / 2);

		return player;
	}

	Player resetPlayer(Player& player)
	{


		player.maxBullets = 1;
		player.currentBullets = 1;
		player.hp = 10;
		player.score = 0;
		player.speed = 10;
		player.rotation = 0;
		player.pos.x = static_cast<float>(screenWidth / 2);
		player.pos.y = static_cast<float>(screenHeight / 2);
		return player;
	}

	void drawPlayer(Player player)
	{
		Rectangle defaultShipState = {0, 0, 32, 32};
		Rectangle movingShipState = {0, 30, 32, 32};
		Rectangle dashingShipState = {0, 60, 32, 32};

		Rectangle sourceDest = {player.pos.x, player.pos.y, 32, 32};
		
		DrawTexturePro(player.Spaceship, defaultShipState, sourceDest, player.pivot, static_cast<float>((player.rotation + 180.0)), WHITE);
		
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			if (player.speed >= 10.0f)
			{
				DrawTexturePro(player.Spaceship, dashingShipState, sourceDest, player.pivot, static_cast<float>((player.rotation + 180.0)), WHITE);
			}
			else
			{
				DrawTexturePro(player.Spaceship, movingShipState, sourceDest, player.pivot, static_cast<float>((player.rotation + 180.0)), WHITE);
			}
		}
		
		
			
		
	}

	Player actionUpdate(Player& player)
	{
		Vector2 mousePos = GetMousePosition();
		Vector2 rotation = { mousePos.x - player.pos.x,mousePos.y - player.pos.y };
		double quadrantSum = 0.0;

		if (mousePos.x < player.pos.x)
		{
			
				quadrantSum = 180.0;
			
		}
		if (mousePos.x > player.pos.x )
		{
			if (mousePos.y < player.pos.y)
			{
				quadrantSum = 360.0;
			}
			else if (mousePos.y > player.pos.y)
			{
				quadrantSum = 0.0;
			}
		}

		double angle = ((atan2(rotation.y, rotation.x)));
		angle = (angle * 180 / PI);
		angle += quadrantSum;

		player.rotation += angle * GetFrameTime();

		return player;
	}
}
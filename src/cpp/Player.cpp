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
		player.speed = 0.0f;
		player.maxSpeed = 100.0f;
		player.acceleration = 30.0f;
		player.pivot.x = 16.0f;
		player.pivot.y = 16.0f;
		player.rotation = 0.0f;
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
		player.speed = 0.0f;
		player.maxSpeed = 100.0f;
		player.acceleration = 30.0f;
		player.rotation = 0.0f;
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
		
		DrawTexturePro(player.Spaceship, defaultShipState, sourceDest, player.pivot, player.rotation, WHITE);
	
		
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			if (player.speed > 100.0f)
			{
				DrawTexturePro(player.Spaceship, dashingShipState, sourceDest, player.pivot,player.rotation, WHITE);
			}
			else
			{
				DrawTexturePro(player.Spaceship, movingShipState, sourceDest, player.pivot, player.rotation, WHITE);
			}


		}
		
		
			
		
	}

	Player actionUpdate(Player& player)
	{
		Vector2 mousePos = GetMousePosition();
		Vector2 rotation = { mousePos.x - player.pos.x,mousePos.y - player.pos.y };
		Vector2 direction = { 0.0f,0.0f };
		Vector2 directionNorm = { 0.0f,0.0f };

		//double quadrantSum = 0.0;

		/*if (mousePos.x < player.pos.x)
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
		}*/

		float angle = ((atan2(rotation.y, rotation.x)));
		angle = (angle * 180 / PI);
		//angle += quadrantSum;

		player.rotation = angle - 270.0f;


		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			 direction = { mousePos.x - player.pos.x,mousePos.y - player.pos.y };
			 directionNorm = Vector2Normalize(direction);

			player.speed += player.acceleration * GetFrameTime();

		}

		player.pos.x += directionNorm.x * GetFrameTime() * player.speed;
		player.pos.y += directionNorm.y * GetFrameTime() * player.speed;


		return player;
	}
}
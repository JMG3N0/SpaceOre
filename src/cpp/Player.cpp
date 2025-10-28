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
		player.speed = { 0.0f, 0.0f };
		player.maxSpeed = 100.0f;
		player.currentSpeed = 30.0f;
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
		player.speed = { 0.0f, 0.0f };
		player.currentSpeed = 30.0f;
		player.maxSpeed = 100.0f;
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
		
		DrawTexturePro(player.Spaceship, defaultShipState, sourceDest, player.pivot, (player.rotation - 270.0f), WHITE);
	
		
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			if (Vector2Length(player.speed) > 100)
			{
				DrawTexturePro(player.Spaceship, dashingShipState, sourceDest, player.pivot, (player.rotation - 270.0f), WHITE);
			}
			else
			{
				DrawTexturePro(player.Spaceship, movingShipState, sourceDest, player.pivot, (player.rotation - 270.0f), WHITE);
			}


		}
		
		
			
		
	}

	Player actionUpdate(Player& player)
	{
		Vector2 mousePos = GetMousePosition();
		Vector2 rotation = { mousePos.x - player.pos.x,mousePos.y - player.pos.y };
		Vector2 direction = Vector2Subtract(mousePos, player.pos);
		

		
		player.rotation = (atan2f(rotation.y, rotation.x) * RAD2DEG) ;


		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			Vector2 acceleration = Vector2Scale(Vector2Normalize(direction), player.currentSpeed * GetFrameTime());
			

			player.speed = Vector2Add(player.speed, acceleration);
			

		}

		if (Vector2Length(player.speed) > player.maxSpeed)
		{
			player.speed = Vector2Scale(Vector2Normalize(player.speed), player.maxSpeed);
		}

		player.pos = Vector2Add(player.pos, Vector2Scale(player.speed, GetFrameTime()));

		if (player.pos.x < -player.radius)
			player.pos.x = static_cast<float>(GetScreenWidth()) + player.radius;

		if (player.pos.x > GetScreenWidth() + player.radius)
			player.pos.x = -player.radius;

		if (player.pos.y < -player.radius)
			player.pos.y = static_cast<float>(GetScreenHeight()) + player.radius;

		if (player.pos.y > GetScreenHeight() + player.radius)
			player.pos.y = -player.radius;

		return player;
	}
}
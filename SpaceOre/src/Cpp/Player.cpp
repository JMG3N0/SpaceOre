 #include "Player.h"
#include "raymath.h"


namespace space_ore
{

	int screenWidth = 1024;
	int screenHeight = 768;

	Player initializePlayer(Player& player)
	{
		player.Spaceship = LoadTexture("SpaceOre/res/spaceship_sheet.png");
		player.maxBullets = 1;
		player.currentBullets = 1;
		player.hp = 10;
		player.score = 0;
		player.maxScore = 0;
		player.speed = 10;
		player.pivot.x = 50;
		player.pivot.y = 50;
		player.rotation = 0;
		player.radius = 10;
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
		Rectangle defaultShipState = {0, 0, 48, 35};
		Rectangle movingShipState = {48, 0, 48, 35};
		Rectangle dashingShipState = {96, 0, 48, 35};

		Rectangle sourceDest = {player.pos.x, player.pos.y, 100, 100};
		
		
		
		if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
		{
			if (player.speed >= 10)
			{
				DrawTexturePro(player.Spaceship, dashingShipState, sourceDest, player.pivot, (player.rotation + 180), WHITE);
			}
			else
			{
				DrawTexturePro(player.Spaceship, movingShipState, sourceDest, player.pivot, (player.rotation + 180), WHITE);
			}
		}
		else
		{
			DrawTexturePro(player.Spaceship,defaultShipState, sourceDest, player.pivot, (player.rotation +180), WHITE);
		}
	}

	Player actionUpdate(Player& player)
	{
		Vector2 mousePos = GetMousePosition();
		float rotationX = mousePos.x - player.pos.x;
		float rotationY = mousePos.y - player.pos.y;
		float quadrantSum = 0;

		if (mousePos.x < player.pos.x)
		{
			
				quadrantSum = 180;
			
		}
		if (mousePos.x > player.pos.x )
		{
			if (mousePos.y < player.pos.y)
			{
				quadrantSum = 360;
			}
			else
			{
				quadrantSum = 0;
			}
		}

		float angle = ((atan2(rotationY, rotationX)) + quadrantSum);
		angle = angle * PI / 180;
		
		player.rotation += angle * GetFrameTime();

		return player;
	}
}
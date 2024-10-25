 #include "Player.h"

namespace space_ore
{

	int screenWidth = 1024;
	int screenHeight = 768;

	Player initializePlayer(Player& player)
	{


		player.maxBullets = 1;
		player.currentBullets = 1;
		player.hp = 10;
		player.color = BLUE;
		player.score = 0;
		player.maxScore = 0;
		player.speed = 10;
		player.pivot.x = 0;
		player.pivot.y = 0;
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
		player.pivot.x = 0;
		player.pivot.y = 0;
		player.rotation = 0;
		player.pos.x = static_cast<float>(screenWidth / 2);
		player.pos.y = static_cast<float>(screenHeight / 2);
		return player;
	}

}
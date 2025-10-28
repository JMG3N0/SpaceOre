#include "raylib.h"

namespace space_ore
{


	struct Player
	{
		Texture2D Spaceship;
		Vector2 pos;
		Vector2 pivot;
		Vector2 speed;
		int hp;
		int score;
		int maxScore;
		int maxBullets;
		int currentBullets;
		float maxSpeed;
		float currentSpeed;
		float radius;
		float rotation;
	};


	Player initializePlayer(Player& player);
	Player resetPlayer(Player& player);
	Player actionUpdate(Player& player);
	void drawPlayer(Player player);

}
#include "raylib.h"

namespace space_ore
{


	struct Player
	{
		Texture2D Spaceship;
		Vector2 pos;
		Vector2 pivot;
		int hp;
		int score;
		int maxScore;
		int maxBullets;
		int currentBullets;
		float speed;
		float radius;
		double rotation;
	};


	Player initializePlayer(Player& player);
	Player resetPlayer(Player& player);
	Player actionUpdate(Player& player);
	void drawPlayer(Player player);

}
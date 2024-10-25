#include "raylib.h"

namespace space_ore
{

	struct Player
	{
		Rectangle ship;
		Vector2 pos;
		Vector2 pivot;
		Color color;
		int hp;
		int score;
		int maxScore;
		int maxBullets;
		int currentBullets;
		float speed;
		float rotation;
		float radius;
	};

	


	Player initializePlayer(Player& player);
	Player resetPlayer(Player& player);

}
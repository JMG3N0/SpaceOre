#include "raylib.h"

struct Player
{
	Vector2 pos;
	Color color;
	int hp;
	int score;
	int maxBullets;
	int currentBullets;
	float speed;
};

Player setPlayer(Player* player);
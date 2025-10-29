#pragma once

#include "raylib.h"

#include "Player.h"


namespace space_ore
{

	struct Bullet
	{
		Vector2 pos;
		Vector2 currentSpeed;
		bool active;
		float radius;
		float acceleration;
	};

	void initializeBullets(Bullet(&bullets)[10], int arraySize);
	void shootBullet(Bullet bullets[], Vector2 position, Vector2 direction, Player player);
	void updateBullet(Bullet& bullet);
	void drawBullet(Bullet bullet, Texture2D texture, float rotation);

}
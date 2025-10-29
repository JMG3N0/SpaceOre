#pragma once

#include "raylib.h"

#include "Player.h"

#include "Bullet.h"

namespace space_ore
{


	enum class Size { Large, Medium, Small };

	const int largeMaxNumb = 10;
	const int mediumMaxNumb = 20;
	const int smallMaxNumb = 40;
	
	const float largeMaxSize = 30.0f;
	const float mediumMaxSize = 20.0f;
	const float smallMaxSize = 10.0f;


	static int asteroidCount = 0;
	static int triggerBigAster = 0;

	struct Asteroid
	{
		Vector2 pos;
		Vector2 speed;
		Size size;
		float radius;
		bool active;
	};

	void initializeAsteroid(Asteroid& asteroid, Vector2 position, Vector2 speed, Size size);
	void updateAsteroid(Asteroid& asteroid);
	void drawAsteroid(Asteroid& asteroid, Texture2D& Sprite);
	void destroyAsteroid(Asteroid& asteroid, Asteroid asteroids[], Player& player);
	void bulletAsteroidCollision(Bullet (&bullets)[10], Asteroid asteroids[], Player& player);
	void playerBulletCollision(Player& player, Asteroid asteroids[]);
}
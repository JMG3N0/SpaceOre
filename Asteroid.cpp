#include "Asteroid.h"

#include "raymath.h"



namespace space_ore
{
	void initializeStarterAsteroids(Asteroid asteroids[])
	{
		for (int  i = 0; i < largeMaxNumb; i++)
		{
			Vector2 position = { 0.0f,0.0f };
			Vector2 speed = { 0.0f, 0.0f };

			asteroidRandomPosAndSpeed(position, speed);

			initializeAsteroid(asteroids[i], position, speed, Size::Large);
			asteroidCount++;
		}
	}

	void initializeAsteroid(Asteroid& asteroid, Vector2 position, Vector2 speed, Size size, Asteroid asteroids[])
	{

		
		
		asteroid.pos = position;
		asteroid.speed = speed;
		asteroid.size = size;
		asteroid.active = true;
		asteroidCount++;

		switch (size)
		{
		case Size::Large:
			asteroid.radius = largeMaxSize;
			break;
		case Size::Medium:
			asteroid.radius = mediumMaxSize;
			break;
		case Size::Small:
			asteroid.radius = smallMaxSize;
			break;
		default:
			break;
		}


	}

	void updateAsteroid(Asteroid& asteroid)
	{
		if (asteroid.active == true)
		{
			asteroid.pos = Vector2Add(asteroid.pos, Vector2Scale(asteroid.speed, GetFrameTime()));

			if (asteroid.pos.x < 0.0f)
			{
				asteroid.pos.x = static_cast<float>(GetScreenWidth());
			}
			else if (asteroid.pos.x > static_cast<float>(GetScreenWidth()))
			{
				asteroid.pos.x = 0.0f;
			}

			if (asteroid.pos.y < 0.0f)
			{
				asteroid.pos.y = static_cast<float>(GetScreenHeight());
			}
			else if (asteroid.pos.y > static_cast<float>(GetScreenHeight()))
			{
				asteroid.pos.y = 0.0f;
			}
		}
	}

	void drawAsteroid(Asteroid& asteroid, Texture2D& sprite)
	{
		if (asteroid.active == true)
		{
			float scale = asteroid.radius / 8.0f;
			Rectangle sourceRect = { 0.0f, 0.0f, 16.0f, 16.0f };
			Rectangle destRect = { asteroid.pos.x, asteroid.pos.y, 16.0f * scale, 16.0f * scale };
			Vector2 origin = { 8.0f, 8.0f };

			DrawTexturePro(sprite, sourceRect, destRect, origin, 0.0f, WHITE);
		}
	}

	void destroyAsteroid(Asteroid& asteroid, Asteroid asteroids[], Player& player)
	{
		asteroid.active = false;
		asteroidCount--;

		switch (asteroid.size)
		{
		case Size::Large:
			player.score += 8;
			break;
		case Size::Medium:
			player.score += 6;
			break;
		case Size::Small:
			player.score += 4;
			break;
		default:
			break;
		}

		if (asteroid.size == Size::Large || asteroid.size == Size::Medium)
		{
			Size newAsterSize;

			float angleRotation1 = static_cast<float>(GetRandomValue(15, 45));
			float angleRotation2 = static_cast<float>(-GetRandomValue(15, 45));

			Vector2 newSpeed1 = Vector2Rotate(asteroid.speed, angleRotation1);
			Vector2 newSpeed2 = Vector2Rotate(asteroid.speed, angleRotation2);

			int maxAsteroids = largeMaxNumb + mediumMaxNumb + smallMaxNumb;


			if (asteroid.size == Size::Large)
			{
				newAsterSize = Size::Medium;
			}
			else
			{
				newAsterSize = Size::Small;
			}

			for (int i = 0; i < maxAsteroids; i++)
			{
				if(!asteroids[i].active)
				{
					initializeAsteroid(asteroids[i], asteroid.pos, newSpeed1, newAsterSize);
					asteroidCount++;

					if (i + 1 < maxAsteroids)
					{
						initializeAsteroid(asteroids[++i], asteroid.pos, newSpeed2, newAsterSize);
						asteroidCount++;
					}
				}
			}
		}
	}

	void asteroidRandomPosAndSpeed(Vector2& position, Vector2& speed)
	{
		
		int border = GetRandomValue(0, 3);
		switch (border)
		{
		case 0: // Left border
			position = { 0.0f, static_cast<float>(GetRandomValue(0, GetScreenHeight())) };
			speed = { 100.0f, static_cast<float>(GetRandomValue(-100, 100)) };
			break;
		case 1: // Right border
			position = { static_cast<float>(GetScreenWidth()), static_cast<float>(GetRandomValue(0, GetScreenHeight())) };
			speed = { -100.0f, static_cast<float>(GetRandomValue(-100, 100)) };
			break;
		case 2: // Top border
			position = { static_cast<float>(GetRandomValue(0, GetScreenWidth())), 0.0f };
			speed = { static_cast<float>(GetRandomValue(-100, 100)), 100.0f };
			break;
		case 3: // Bottom border
			position = { static_cast<float>(GetRandomValue(0, GetScreenWidth())), static_cast<float>(GetScreenHeight()) };
			speed = { static_cast<float>(GetRandomValue(-100, 100)), -100.0f };
			break;
		}
	}

	void bulletAsteroidCollision(Bullet(&bullets)[10], Asteroid asteroids[], Player& player)
	{
		for (int i = 0; i < player.maxBullets; i++)
		{
			if (bullets[i].active == true)
			{
				for (int j = 0; j < asteroidCount; j++)
				{
					if (asteroids[j].active == true)
					{
						float distance = Vector2Distance(bullets[i].pos, asteroids[j].pos);
						if (distance < bullets[i].radius + asteroids[j].radius)
						{
							bullets[i].active = false;
							destroyAsteroid(asteroids[j], asteroids, player);

							if (asteroids[j].size == Size::Small)
							{
								triggerBigAster++;
								if (triggerBigAster >= 3)
								{
									Vector2 speed = { 0.0f, 0.0f };
									Vector2 position = { 0.0f, 0.0f };
									asteroidRandomPosAndSpeed(position, speed);
									initializeAsteroid(asteroids[j], position, speed, Size::Large);
									triggerBigAster = 0;
								}
							}
						}
					}
				}
			}
		}
	}

	void playerBulletCollision(Player& player, Asteroid asteroids[])
	{
		if (player.iFramesActive == true)
		{
			return;
		}

		for (int i = 0; i < asteroidCount; i++)
		{
			if (asteroids[i].active == true)
			{
				float distance = Vector2Distance(player.pos, asteroids[i].pos);
				if (distance < player.radius + asteroids[i].radius)
				{
					player.hp--;
					asteroids[i].active = false;

					player.iFramesActive = true;
					player.iFramesTimer = 5.0f;
				}
			}
		}
	}
}
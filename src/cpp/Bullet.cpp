#include "Bullet.h"

#include "raymath.h"



namespace space_ore
{
	void initializeBullets(Bullet(&bullets)[10], int arraySize)
	{
		for (int i = 0; i < arraySize; i++)
		{
			bullets[i].active = false;
			bullets[i].radius = 10.0f;
			bullets[i].acceleration = 500.0f;
		}
	}

	void shootBullet(Bullet bullets[], Vector2 position, Vector2 direction, Player player)
	{
		if (currentBullets < player.maxBullets)
		{
			for (int i = 0; 1 < player.maxBullets; i++)
			{
				if (!bullets[i].active)
				{
					bullets[i].pos = position;
					bullets[i].currentSpeed = Vector2Scale(Vector2Normalize(direction), bullets[i].acceleration);
					bullets[i].active = true;
					currentBullets++;
				}
			}
		}


		
	}

	void updateBullet(Bullet& bullet)
	{
		if (bullet.active)
		{
			bullet.pos = Vector2Add(bullet.pos, Vector2Scale(bullet.currentSpeed, GetFrameTime()));


			if (bullet.pos.x < 0.0f || bullet.pos.x > static_cast<float>(GetScreenWidth()) || bullet.pos.y < 0.0f || bullet.pos.y > static_cast<float>(GetScreenHeight()))
			{
				bullet.active = false;
				currentBullets--;
			}

		}
	}
	void drawBullet(Bullet bullet, Texture2D texture, float rotation)
	{
		if (bullet.active)
		{
			Rectangle sourceRect = { 0.0f, 0.0f, 16.0f, 16.0f };
			Rectangle destRect = {bullet.pos.x, bullet.pos.y, bullet.radius *2, bullet.radius*2 };
			Vector2 origin = { 20.0f, 20.0f };

			DrawTexturePro(texture, sourceRect, destRect, origin, rotation, WHITE);;
		}
	}
}
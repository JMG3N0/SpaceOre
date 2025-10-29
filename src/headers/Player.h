#include "raylib.h"



namespace space_ore
{
	static int currentBullets;

	struct Player
	{
		

		Texture2D Spaceship;
		Vector2 pos;
		Vector2 pivot;
		Vector2 currentSpeed;
		bool iFramesActive;
		int hp;
		int score;
		int maxScore;
		int maxBullets;
		float maxSpeed;
		float acceleration;
		float radius;
		float rotation;
		float iFramesTimer;
	};


	Player initializePlayer(Player& player);
	Player resetPlayer(Player& player);
	Player actionUpdate(Player& player);
	void drawPlayer(Player player);
	void iFrames(Player& player);
	

}
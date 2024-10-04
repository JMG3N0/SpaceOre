#include "Player.h"
#include "Globals.h"

Player setPlayer(Player* player)
{
	player->maxBullets = 1;
	player->currentBullets = 1;
	player->hp = 10;
	player->color = BLUE;
	player->score = 0;
	player->speed = 10;
	player->pos.x = static_cast<float>(screenWeight / 2);
	player->pos.y = static_cast<float>(screenHeight / 2);
}

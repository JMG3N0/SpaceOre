#pragma once


namespace space_ore
{

	enum Menu
	{
		Main = 0, Play, Credits, Quit, GameOver
	};

	

	void StartGame();
	void GameplayLoop();
	void ScreenUpdate();
	void TitleScreen();
	void CreditsScreen();
	void GameOverScreen();
}

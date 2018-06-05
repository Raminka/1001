#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "MainMenu.h"
#include "Drawing.h"
#include "ObjectManager.h"
#include "PlayerPaddle.h"
#include "Ball.h"
#include <Box2D\Box2D.h>


class Game
{
public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowMenu();

	static void InitGame(int level);

	enum GameState {
		Uninitialized, ShowingMenu, Playing, Exiting
	};

	static GameState gameState;
	static sf::RenderWindow mainWindow;

	//static Drawing drawing;
	static ObjectManager objectManager;

	static b2World world;
};
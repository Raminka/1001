#pragma once
#include "SFML/Graphics.hpp"
#include "MainMenu.h"
#include "ObjectManager.h"
#include <Box2D\Box2D.h>
#include "MyContactListener.h"
#include "PlayerPaddle.h"
#include "Ball.h"

class Game
{
public:
	static void Start();

private:
	static bool IsExiting();
	static void GameLoop();
	
	static void ShowMenu();

	enum GameState {
		Uninitialized, ShowingMenu, Playing, Exiting 
	};

	static GameState gameState;
	static sf::RenderWindow mainWindow;

	//gestion de tous les objets mobiles et obstacles
	static ObjectManager objectManager;

	static b2World world;

	/**init des obstacles du jeu*/
	static void InitGame(int level, MainMenu::ModePlay mode);

	//detection des contacts
	static MyContactListener myContactListenerInstance;

	static MainMenu mainMenu;
};
#include "stdafx.h"
#include "Game.h"
#include <iostream>
//#define _CRTDBG_MAP_ALLOC #include <stdlib.h> #include <crtdbg.h>  


void Game::Start(void)
{
	if (gameState != Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1024, 768, 32), "1001");
	mainMenu.create(mainWindow);
	b2Vec2 gravity(0.0f, 0.0f);//pas de gravité dans le jeu
	world.SetGravity(gravity);
	world.SetContactListener(&myContactListenerInstance);
	mainWindow.setFramerateLimit(70);

	//on commence par le menu
	gameState = Game::ShowingMenu;

	while (!IsExiting())
	{
		GameLoop();
	}

	objectManager.clear();
	
	//_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
	//_CrtDumpMemoryLeaks();
	mainWindow.clear();
	mainWindow.close();
	mainMenu.clear();
}

bool Game::IsExiting()
{
	if (gameState == Game::Exiting)
	{
		return true;
	}
	else
		return false;
}

void Game::GameLoop()
{	
	switch (gameState)
	{
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		
		case Game::Playing:
		{
			sf::Event currentEvent;
			mainWindow.pollEvent(currentEvent);
			mainWindow.clear(sf::Color(0, 150, 255, 255));

			/*draw les obstacles*/
			objectManager.Update(mainWindow);
			mainWindow.display();

			if (currentEvent.type == sf::Event::Closed) {
				gameState = Game::Exiting;
			}
			
			/*les commandes des joueurs*/
			objectManager.handleInput(currentEvent);


			world.Step(1 / 60.f, 8, 3);

			if (currentEvent.type == sf::Event::KeyPressed)
				{
				if (currentEvent.key.code == sf::Keyboard::Escape) {
					gameState = Game::ShowingMenu;
					objectManager.clear();
				}
			}
	
		break;
		}
	}
}


void Game::ShowMenu()
{
	//MainMenu mainMenu;
	MainMenu::MainMenuResult result = mainMenu.Show(mainWindow);
	switch (result.action)
	{
	case button::Exit:
		gameState = Game::Exiting;
		break;
	case button::PlayLVL1:
		gameState = Game::Playing;
		InitGame(1,result.mode);
		break;
	case button::PlayLVL2:
		gameState = Game::Playing;
		InitGame(2, result.mode);
		break;
	default:
		ShowMenu();
		break;
	}
}

void Game::InitGame(int level,MainMenu::ModePlay mode ) {
	/*on efface les objets precedents*/
	objectManager.clear ();

	pugi::xml_document doc;
	pugi::xml_parse_result result;
	if (level == 1) {
		 result = doc.load_file("../lvl1.xml");
		 if (!result)
		 {
			 std::cerr << "Could not open file lvl1.xml" << std::endl;
			 gameState = Game::ShowingMenu;
			 return;
		 }
	}
	else if (level == 2) {
		result = doc.load_file("../MaBibliotheque/lvl2.xml");
		if (!result)
		{
			std::cerr << "Could not open file lvl2.xml" << std::endl;
			gameState = Game::ShowingMenu;
			return;
		}
	}
	if (!result)
	{
		std::cerr << "no file xml" << std::endl;
		gameState = Game::ShowingMenu;
		return;
	}
	pugi::xml_node root = doc.child("Drawing");
	objectManager.initObjects(root, &world,mainWindow);//initialisation des objets

	switch (mode) //choix de mode de jeu
	{
	case MainMenu::Light:
		objectManager.darkMode = false;
		break;
	case MainMenu::Dark:
		objectManager.darkMode = true;
		break;
	}



}


Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
ObjectManager Game::objectManager;
b2World Game::world=b2World(b2Vec2(0.0f, 0.0f));
MyContactListener Game::myContactListenerInstance;
MainMenu Game::mainMenu;
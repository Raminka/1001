#include "stdafx.h"
#include "Game.h"
#include <iostream>

Game::Game() 
	: gameState ( Uninitialized)
{
	//mainWindow.create(sf::VideoMode(1024, 768, 32), "1001");
	mainWindow.create(sf::VideoMode(1280, 960, 32), "1001");
	b2Vec2 gravity(0.0f, 0.0f);//pas de gravité dans le jeu
	world.SetGravity(gravity);
	world.SetContactListener(&myContactListenerInstance);
	mainWindow.setFramerateLimit(70);

	/*initialisation des boutons dans le mainMenu*/
	mainMenu.create(mainWindow);
}

void Game::Start(void)
{
	/*on commence par l'affichage de Menu*/
	gameState = Game::ShowingMenu;

	while (!IsExiting())
	{
		GameLoop();
	}

	
	objectManager.clear();
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

			/*mise à jour des objets de jeu*/
			objectManager.Update(mainWindow);
			mainWindow.display();

			/*la gestion des commandes des joueurs */
			objectManager.handleInput(currentEvent);

			if (currentEvent.type == sf::Event::Closed) {
				gameState = Game::Exiting;
			}
			else if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape) {
					gameState = Game::ShowingMenu;
					objectManager.clear();
				}
			}

			world.Step(1 / 60.f, 8, 3);
		break;
		}
	}
}


void Game::ShowMenu()
{
	/*recouperation du choix de l'utilisateur*/
	MainMenu::MainMenuResult result = mainMenu.Show(mainWindow);
	switch (result.action)
	{
	case button::Exit:
		gameState = Game::Exiting;
		break;
	case button::PlayLVL1:
		gameState = Game::Playing;
		/*on initialise le jeu avec le niveau 1 et mode correspondant*/
		InitGame(1,result.mode);
		break;
	case button::PlayLVL2:
		gameState = Game::Playing;
		/*on initialise le jeu avec le niveau 2 et mode correspondant*/
		InitGame(2, result.mode);
		break;
	default:
		ShowMenu();
		break;
	}
}

void Game::InitGame(int level,MainMenu::ModePlay mode ) {
	/*on recoupere le fichier contenant le niveau correspondant*/
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

	/*initialisation des objets à partir de root*/
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


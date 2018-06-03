#include "stdafx.h"
#include "Game.h"
#include <iostream>

void Game::Start(void)
{
	if (gameState != Uninitialized)
		return;

	mainWindow.create(sf::VideoMode(1024, 768, 32), "1001");
	gameState = Game::ShowingMenu;

	while (!IsExiting())
	{
		GameLoop();
	}

	mainWindow.close();
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
			mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
			//drawing.Draw(mainWindow);
			mainWindow.display();
			while (mainWindow.pollEvent(currentEvent))
			{
				if (currentEvent.type == sf::Event::Closed) {
					gameState = Game::Exiting;
					
				}
				if (currentEvent.type == sf::Event::KeyPressed)
				{
					if (currentEvent.key.code == sf::Keyboard::Escape) {
						mainWindow.clear();
						ShowMenu();
					}
				}
				mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
			//	drawing.Draw(mainWindow);
				mainWindow.display();
			}
			break;
		}
	}
}


void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(mainWindow);
	switch (result)
	{
	case MainMenu::Exit:
		gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		/*
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("../construction.xml");
		if (!result)
		{
		std::cerr << "Could not open file construction.xml" << std::endl;
		return ;//TODO :: traiter le cas où le fichier n'est pas trouvé
		}
		pugi::xml_node root = doc.child("Drawing");
		drawing.update(root);
		*/
		gameState = Game::Playing;
		break;
	}
}


Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
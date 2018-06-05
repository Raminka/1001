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
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);
	switch (gameState)
	{
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		
		case Game::Playing:
		{
			
			
			mainWindow.clear(sf::Color(sf::Color(0, 0, 0)));
			drawing.Draw(mainWindow);
			objectManager.DrawAll(mainWindow);
			mainWindow.display();
			
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
		InitGame(1);
		gameState = Game::Playing;
		break;
	}
}

void Game::InitGame(int level ) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../construction.xml");
	if (!result)
	{
		std::cerr << "Could not open file construction.xml" << std::endl;
		return;//TODO :: traiter le cas où le fichier n'est pas trouvé
	}
	pugi::xml_node root = doc.child("Drawing");
	drawing.update(root);

	PlayerPaddle *player1 = new PlayerPaddle();
	PlayerPaddle *player2 = new PlayerPaddle();
	Ball *ball1 = new Ball();
	Ball *ball2 = new Ball();
	player1->SetPosition(0, (mainWindow.getSize().y-player1->getSizeY()) / 2);
	player2->SetPosition(mainWindow.getSize().x-player2->getSizeX(), (mainWindow.getSize().y-player2->getSizeY())/2);
	ball1->SetPosition(player1->getSizeX(), (mainWindow.getSize().y - ball1->getSizeY()) / 2);
	ball2->SetPosition(mainWindow.getSize().x - 2*player2->getSizeX(), (mainWindow.getSize().y - ball2->getSizeY()) / 2);
	objectManager.AddMovingObject("player1", std::move(player1));
	objectManager.AddMovingObject("player2", std::move(player2));
	objectManager.AddMovingObject("ball1", std::move(ball1));
	objectManager.AddMovingObject("ball2", std::move(ball2));
}


Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
Drawing Game::drawing;
ObjectManager Game::objectManager;
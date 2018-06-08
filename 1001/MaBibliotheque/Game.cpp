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
			mainWindow.clear(sf::Color(0, 150, 255, 255));
			/*draw les obstacles*/
			objectManager.Update(mainWindow);
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
					
					/*les commandes des joueurs*/
					objectManager.handleInput(currentEvent);
				}
				
				world.Step(1 / 60.f, 8, 3);
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
		gameState = Game::Playing;
		InitGame(1);
		break;
	}
}

void Game::InitGame(int level ) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("../construction.xml");
	if (!result)
	{
		std::cerr << "Could not open file construction.xml" << std::endl;
		gameState = Game::ShowingMenu;
		return;
	}
	pugi::xml_node root = doc.child("Drawing");
	objectManager.initObstacles(root, &world,mainWindow);

	b2Vec2 gravity(0.0f, 0.0f);
	world.SetGravity(gravity); 
	
	PlayerPaddle *player1 = new PlayerPaddle(&world, 20, (mainWindow.getSize().y - 90) / 2);
	PlayerPaddle *player2 = new PlayerPaddle(&world, mainWindow.getSize().x - 20, (mainWindow.getSize().y - 90) / 2);
	Ball *ball1=new Ball{ &world,(double)30,(double) (mainWindow.getSize().y - 15) / 2 };
	Ball *ball2 = new Ball(&world, mainWindow.getSize().x - 70, (mainWindow.getSize().y - 15) / 2);
	objectManager.AddMovingObject("player1", player1);
	objectManager.AddMovingObject("player2", player2);
	objectManager.AddMovingObject("ball1", ball1);
	objectManager.AddMovingObject("ball2", ball2);
	mainWindow.setFramerateLimit(70);

	

	//in FooTest constructor
	world.SetContactListener(&myContactListenerInstance);

	
}


Game::GameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mainWindow;
ObjectManager Game::objectManager;
b2World Game::world=b2World(b2Vec2(0.0f, 0.0f));
MyContactListener Game::myContactListenerInstance;
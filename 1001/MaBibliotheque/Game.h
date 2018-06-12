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
	Game();
	
	/*lancement de jeu*/
	void Start();

private:
	/*vérification si l'utilisateur a décidé de quitter le jeu*/
	bool IsExiting();

	/*design pattern qui affiche en continu le jeu*/
	void GameLoop();
	
	/*l'affichage de menu*/
	void ShowMenu();
	MainMenu mainMenu;

	/*l'état de jeu en fonction de choix d'utilisateur*/
	enum GameState {
		Uninitialized, ShowingMenu, Playing, Exiting 
	};
	GameState gameState;

	sf::RenderWindow mainWindow;
	b2World world = b2World(b2Vec2(0.0f, 0.0f));	
	//detection des contacts
	MyContactListener myContactListenerInstance;

	//gestion de tous les objets mobiles et obstacles
	 ObjectManager objectManager;

	/**init des objets du jeu*/
	 void InitGame(int level, MainMenu::ModePlay mode);



};
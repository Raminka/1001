#pragma once
#include "MovingObject.h"
#include "Obstacle.h"
#include <memory>
#include "Rock.h"
#include "Brick.h"
#include "Wall.h"
#include "LightSwitch.h"
#include "PlayerPaddle.h"
#include "Ball.h"
#include <iostream>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	/*initialisation des �l�ments de jeu*/
	void initObjects(pugi::xml_node node, b2World *world, sf::RenderWindow & window);
	
	/*recalcule de positio et draw*/
	void Update(sf::RenderWindow& window);
	
	/*deplacements de joueur*/
	void handleInput(sf::Event event);

	/*on efface les �l�ments de jeu precedent*/
	void clear();

	/*est ce que le jeu s'arrete?
	le jeu s'arrete si un des deux joueurs touche le mur droite ou le mur gauche*/
	bool Stop;
	/*est ce que le mode de jeu est dark? */
	bool darkMode;

	enum movingObjectsNames {player1, player2, ball1, ball2};

private:
	/*Balls et playerPaddle*/
	std::unique_ptr<MovingObject> movingObjects[4];

	/*les obstacles de jeu*/
	std::vector<std::unique_ptr<Obstacle>> obstacles;

	/*affichage sfml*/
	void DrawAll(sf::RenderWindow& renderWindow);

	/*cinq elements permet de cr�er le mode Dark*/
	std::vector<sf::CircleShape> lights;
	sf::RenderTexture target;


		int radiusCircle; //rayon de circle qui diminue au fur � mesure
		int radiusMax;
		int radiusMin;
};
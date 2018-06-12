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

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	/*initialisation des éléments de jeu*/
	void initObjects(pugi::xml_node node, b2World *world, sf::RenderWindow & window);
	
	/*recalcule de positio et draw*/
	void Update(sf::RenderWindow& window);
	
	/*deplacements de joueur*/
	void handleInput(sf::Event event);

	/*on efface les éléments de jeu precedent*/
	void clear();

	/*est ce que le jeu s'arrete?
	le jeu s'arrete si un des deux joueurs touche le mur droite ou le mur gauche*/
	bool Stop;
	/*est ce que le mode de jeu est dark? */
	bool darkMode;

private:
	/*Balls et playerPaddle*/
	std::map<std::string, std::unique_ptr<MovingObject>> movingObjects;
	/*les obstacles de jeu*/
	std::vector<std::unique_ptr<Obstacle>> obstacles;

	/*joueurs et balls*/
	void AddMovingObject(std::string name, MovingObject* movingObject);

	/*affichage sfml*/
	void DrawAll(sf::RenderWindow& renderWindow);

	/*cinq elements permet de créer le mode Dark*/
	std::vector<sf::CircleShape> lights;
	sf::RenderTexture target;


		int radiusCircle; //rayon de circle qui diminue au fur à mesure
		int radiusMax;
		int radiusMin;
};
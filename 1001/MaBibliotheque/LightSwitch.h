#pragma once
#include "Obstacle.h"
class LightSwitch:public Obstacle
{
public:
	/*en touchant cet obstacle on change le mode de jeu de Light vers le Dark ou de Dark vers le Light*/
	LightSwitch(pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	/*fonction qui est appelé après le contact*/
	void startContact() override;

	/*affichage de l'obstacle*/
	void Draw(sf::RenderWindow & window) override;
};


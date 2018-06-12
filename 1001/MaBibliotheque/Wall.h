#pragma once
#include "Obstacle.h"

class Wall: public Obstacle
{
public:
	/*définit la frontiere de jeu*/
	Wall(double x, double y, b2World *world, sf::RenderWindow & window,float dimx,float dimy, std::string label);

	/*affichage sfml*/
	void Draw(sf::RenderWindow & window) override;
	
	void startContact() override;


private:
	/*indiquant quel mur cet objet est exactement*/
	std::string label;
};


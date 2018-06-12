#pragma once
#include "pugixml.hpp"
#include "Obstacle.h"

class Brick : public Obstacle
{
public:
	Brick(pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	/*la focntion supprimant l'objet après le contact*/
	void startContact() override;

	/*affichage de sfml*/
	void Draw(sf::RenderWindow & window) override;	
private:
};


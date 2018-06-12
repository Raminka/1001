#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	/*Rock est indestructible */
	Rock (pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	/*cette fonction est vide pour Rock car le contact n'a aucun effet sur cet obstacle*/
	void startContact() override;

	/*affichage sfml*/
	void Draw(sf::RenderWindow & window) override; 

private:
};


#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	Rock (double fois_x, double fois_y, double fois_dimX, double fois_dimY, b2World *world, sf::RenderWindow & window);
	Rock (pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	void Draw(sf::RenderWindow & window) override; 

private:
	

};


#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	Rock (double fois_x, double fois_y, double fois_dimX, double fois_dimY, b2World *world);
	Rock (pugi::xml_node node, b2World *world);

	double getDimX()const;
	double getDimY() const;
	void Draw(sf::RenderWindow & window) override; 

private:

	double dimX;
	double dimY;
};


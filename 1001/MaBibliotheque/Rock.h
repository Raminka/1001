#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	Rock (double fois_x, double fois_y, double fois_dimX, double fois_dimY);
	Rock (pugi::xml_node node);

	double getDimX()const;
	double getDimY() const;
	void Draw(sf::RenderWindow & window) override; 

private:

	double dimX;
	double dimY;
};


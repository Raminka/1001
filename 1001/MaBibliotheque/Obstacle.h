#pragma once
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>

static const unsigned int tailleX(10);
static const unsigned int tailleY(50);

class Obstacle
{
public:
	Obstacle(double fois_x, double fois_y);
	virtual void Draw(sf::RenderWindow & window) = 0;

	double getX() const;
	double getY() const;

protected:
	double x;
	double y;
};


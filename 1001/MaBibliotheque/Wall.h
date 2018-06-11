#pragma once
#include "Obstacle.h"

class Wall: public Obstacle
{
public:
	Wall(double x, double y, b2World *world, sf::RenderWindow & window,float dimx,float dimy, std::string label);

	void Draw(sf::RenderWindow & window) override;
	void startContact() override;

private:
	std::string label;
};


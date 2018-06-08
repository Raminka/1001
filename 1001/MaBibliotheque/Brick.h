#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Brick : public Obstacle
{
public:
	Brick(double x, double y,b2World *world, sf::RenderWindow & window);
	Brick(pugi::xml_node node, b2World *world, sf::RenderWindow & window);
	void startContact() override;
	
	void Draw(sf::RenderWindow & window) override;	

private:
};


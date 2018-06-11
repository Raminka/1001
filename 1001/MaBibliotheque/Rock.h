#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Rock : public Obstacle
{
public:
	Rock (pugi::xml_node node, b2World *world, sf::RenderWindow & window);
	void startContact() override;

	void Draw(sf::RenderWindow & window) override; 

private:
	

};


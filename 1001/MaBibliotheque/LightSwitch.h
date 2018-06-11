#pragma once
#include "Obstacle.h"
class LightSwitch:public Obstacle
{
public:

	LightSwitch(pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	void startContact() override;

	void Draw(sf::RenderWindow & window) override;
};


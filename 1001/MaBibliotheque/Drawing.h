#pragma once
#include <vector>
#include <memory>
#include "Brick.h"
#include "Rock.h"

class Drawing
{
public:
	Drawing();
	Drawing(pugi::xml_node node, b2World *world);
	void Draw(sf::RenderWindow & window);
	void update(pugi::xml_node node, b2World *world);
private:
	std::vector<std::unique_ptr<Obstacle>> obstacles;
};


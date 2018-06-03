#pragma once
#include <vector>
#include <memory>
#include "Brick.h"
#include "Rock.h"

class Drawing
{
public:
	Drawing();
	Drawing(pugi::xml_node node);
	void Draw(sf::RenderWindow & window);
	void update(pugi::xml_node node);
private:
	std::vector<std::unique_ptr<Obstacle>> obstacles;
};


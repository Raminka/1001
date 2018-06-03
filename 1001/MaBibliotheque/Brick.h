#pragma once
#include <string>
#include "pugixml.hpp"
#include "Obstacle.h"

class Brick : public Obstacle
{
public:
	Brick(double x, double y);
	Brick(pugi::xml_node node);
	void Draw(sf::RenderWindow & window) override;
	//std::string getColor() const;

private:
	double dimX;
	double dimY;
	//std::string color;
};


#include "stdafx.h"
#include "Rock.h"


Rock::Rock(double fois_x, double fois_y, double fois_dimX, double fois_dimY, b2World *world)
	:Obstacle{fois_x,fois_y, world}
	,dimX(fois_dimX * tailleX)
	,dimY(fois_dimY * tailleY)
{
}

Rock::Rock(pugi::xml_node node, b2World *world)
	:Rock { node.attribute("x").as_double(),
	node.attribute("y").as_double(),
	node.attribute("dimX").as_double(),
	node.attribute("dimY").as_double(),
	world
}{}


double Rock::getDimX() const {
	return dimX;
}
double Rock::getDimY() const {
	return dimY;
}

void Rock::Draw (sf::RenderWindow & window) {
	sf::RectangleShape rect(sf::Vector2f(dimX-0.5, dimY-0.5));
	rect.setFillColor(sf::Color(70, 70, 70));
	//	rect.setOutlineColor(sf::Color(255, 255, 255));
	//	rect.setOutlineThickness(0.5);
	rect.setPosition(x + window.getSize().x / 2 - dimX / 2, -y + window.getSize().y / 2 - dimY / 2);
	window.draw(rect);
}
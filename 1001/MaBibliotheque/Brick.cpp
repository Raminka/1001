#include "stdafx.h"
#include "Brick.h"


Brick::Brick(pugi::xml_node node)
	: Brick{ node.attribute("x").as_double(),
	node.attribute("y").as_double()
}
{
}

Brick::Brick(double fois_x, double fois_y)
	: Obstacle{ fois_x,fois_y }
{
	dimX = tailleX;
	dimY = tailleY;
}
void Brick::Draw(sf::RenderWindow & window) {
	sf::RectangleShape rect(sf::Vector2f(dimX-0.5, dimY-0.5));
	rect.setFillColor(sf::Color(255, 255, 255));
//	rect.setOutlineColor(sf::Color(255, 255, 255));
//	rect.setOutlineThickness(0.5);
	rect.setPosition(x + window.getSize().x / 2 - dimX/2, -y + window.getSize().y / 2 - dimY/2);
	window.draw(rect);
}
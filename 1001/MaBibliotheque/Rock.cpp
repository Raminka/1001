#include "stdafx.h"
#include "Rock.h"
#include <iostream>



Rock::Rock(double fois_x, double fois_y, double fois_dimX, double fois_dimY, b2World *world, sf::RenderWindow & window)
	: Obstacle{ fois_x*tailleX,fois_y*tailleY, world, window, fois_dimX * tailleX,fois_dimY * tailleY }
{

}

Rock::Rock(pugi::xml_node node, b2World *world, sf::RenderWindow & window)
	:Rock { node.attribute("x").as_double(),
	node.attribute("y").as_double(),
	node.attribute("dimX").as_double(),
	node.attribute("dimY").as_double(),
	world,
	window
}{}




void Rock::Draw(sf::RenderWindow & window) {
	float scale = 30;
	sf::RectangleShape rect(sf::Vector2f(dimX-0.5, dimY-0.5));
	rect.setFillColor(sf::Color(70, 70, 70));
	rect.setPosition(staticBody->GetPosition().x*scale-dimX/2, staticBody->GetPosition().y*scale-dimY/2);
	window.draw(rect);
}
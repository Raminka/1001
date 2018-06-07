#include "stdafx.h"
#include "Brick.h"



Brick::Brick(pugi::xml_node node, b2World *world, sf::RenderWindow & window)
	: Brick{ node.attribute("x").as_double(),
	node.attribute("y").as_double(),
	world,
	window
}
{
}

Brick::Brick(double fois_x, double fois_y, b2World *world, sf::RenderWindow & window)
	: Obstacle{ fois_x*tailleX,fois_y*tailleY,world,window,tailleX,tailleY }
{
}

void Brick::Draw(sf::RenderWindow & window) {
	float scale = 30.f;
	sf::RectangleShape rect(sf::Vector2f(dimX-0.5, dimY-0.5));
	rect.setFillColor(sf::Color(255, 255, 255));
	rect.setPosition(staticBody->GetPosition().x*scale-dimX/2,staticBody->GetPosition().y*scale-dimY/2);
	window.draw(rect);
}
#include "stdafx.h"
#include "Rock.h"


Rock::Rock(pugi::xml_node node, b2World *world, sf::RenderWindow & window)
	:Obstacle { node.attribute("x").as_double()*tailleX,
	node.attribute("y").as_double()*tailleY,
	world,
	window,
	node.attribute("dimX").as_double()*tailleX,
	node.attribute("dimY").as_double()*tailleY
}{}

void Rock::Draw(sf::RenderWindow & window) {
	sf::RectangleShape rect(sf::Vector2f(dimX-0.5, dimY-0.5));
	rect.setFillColor(sf::Color(70, 70, 70));
	rect.setPosition(staticBody->GetPosition().x*SCALE-dimX/2, staticBody->GetPosition().y*SCALE-dimY/2);
	window.draw(rect);
}

void Rock::startContact() {}
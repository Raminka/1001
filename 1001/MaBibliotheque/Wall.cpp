#include "stdafx.h"
#include "Wall.h"
#include <iostream>



Wall::Wall(double X, double Y, b2World *world, sf::RenderWindow & window,float dimx,float dimy, std::string label)
	: Obstacle(X,Y,world,window,dimx,dimy)
	, label(label)
{
	
}


Wall::~Wall()
{
}

void Wall::Draw(sf::RenderWindow & window) {
	float scale = 30;
	sf::RectangleShape rect(sf::Vector2f(dimX - 0.5, dimY - 0.5));
	rect.setFillColor(sf::Color(70, 70, 70));
	rect.setPosition(staticBody->GetPosition().x*scale-dimX/2, staticBody->GetPosition().y*scale-dimY/2);
	window.draw(rect);
}

void Wall::startContact() {
	
	if ("Left" == label || "Right" == label) {
		toDelete = true;
	}
}
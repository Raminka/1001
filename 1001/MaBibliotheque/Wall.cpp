#include "stdafx.h"
#include "Wall.h"

Wall::Wall(double X, double Y, b2World *world, sf::RenderWindow & window,float dimx,float dimy, std::string label)
	: Obstacle(X,Y,world,window,dimx,dimy)
	, label(label)
{
	
}


void Wall::Draw(sf::RenderWindow & window) {
	sf::RectangleShape rect(sf::Vector2f(dimX - 0.5, dimY - 0.5));
	rect.setFillColor(sf::Color(70, 70, 70));
	rect.setPosition(staticBody->GetPosition().x*SCALE-dimX/2, staticBody->GetPosition().y*SCALE-dimY/2);
	window.draw(rect);
}

void Wall::startContact() {
	if ("Left" == label || "Right" == label) {
		obstacleAction = stopGame;
	}
}
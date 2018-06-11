#include "stdafx.h"
#include "Obstacle.h"
#include <iostream>

Obstacle::Obstacle(double X, double Y, b2World *world, sf::RenderWindow & window, double dimx, double dimy)
	:dimX(dimx)
	,dimY(dimy)
	,x(X + window.getSize().x / 2 )
	,y(Y + window.getSize().y / 2 )
	//,touched(false)
	,m_contact(false)
	, obstacleAction(nothing)
{
	myBodyDef.type = b2_staticBody;
	myBodyDef.position.Set(x / SCALE, y / SCALE);

	staticBody = world->CreateBody(&myBodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(dimX / (2 * SCALE), dimY / (2 * SCALE)); 

	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	staticBody->CreateFixture(&boxFixtureDef);
	staticBody->SetUserData(this);
}

double Obstacle::getX()const {
	return x;
}
double Obstacle::getY() const {
	return y;
}
double Obstacle::getDimX() const {
	return dimX;
}
double Obstacle::getDimY() const {
	return dimY;
}

void Obstacle::clear() {
	staticBody->SetUserData(NULL);
	staticBody->GetWorld()->DestroyBody(staticBody);
}
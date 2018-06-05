#include "stdafx.h"
#include "Obstacle.h"


Obstacle::Obstacle(double fois_x, double fois_y,b2World *world)
	:x(fois_x*tailleX)
	,y(fois_y*tailleY)
{
	b2BodyDef myBodyDef;
	myBodyDef.type = b2_staticBody; 
	myBodyDef.position.Set(getX(), getY()); 
	staticBody = world->CreateBody(&myBodyDef); 
	b2PolygonShape boxShape;
	boxShape.SetAsBox(tailleX, tailleY); //à redefinir la taille
	b2FixtureDef boxFixtureDef;
	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	staticBody->CreateFixture(&boxFixtureDef);
}



double Obstacle::getX()const {
	return x;
}
double Obstacle::getY() const {
	return y;
}
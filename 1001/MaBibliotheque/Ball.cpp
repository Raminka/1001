#include "stdafx.h"
#include "Ball.h"


Ball::Ball(b2World* world, float x, float y)
	: MovingObject{}
{
	Load("../MaBibliotheque/ball.png");

	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(x / SCALE, y / SCALE);
	//myBodyDef.linearVelocity.Set(0, 0);
	//myBodyDef.userData = (void*) "ball";
	body = (world->CreateBody(&myBodyDef));

	b2CircleShape circleShape;
	//circleShape.m_p.Set(0, 0); //position, relative to body position
	circleShape.m_radius = getSizeX() / 2;

	myFixtureDef.density = 1;
	myFixtureDef.restitution = 1;
	myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
	body->CreateFixture(&myFixtureDef);
	update();
}


Ball::~Ball()
{
}



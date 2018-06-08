#include "stdafx.h"
#include "Ball.h"

Ball::Ball(b2World* world, double x, double y)
	: MovingObject{}
{
	Load("../MaBibliotheque/ball.png");

	float SCALE = 30.f;
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(x / SCALE, y / SCALE);
	body = (world->CreateBody(&myBodyDef));

	b2CircleShape circleShape;
	circleShape.m_radius = getSizeX() / (SCALE*2)	;

	myFixtureDef.density = 1;
	myFixtureDef.restitution = 1;
	myFixtureDef.shape = &circleShape; 
	body->CreateFixture(&myFixtureDef);
	if (x < 200) {
		body->ApplyForce(b2Vec2(400, 0), b2Vec2(0, 0), true);
	}
	else {
		body->ApplyForce(b2Vec2(-400, 0), b2Vec2(0, 0), true);
	}
	//body->SetUserData(this);
	update();

}


Ball::~Ball()
{
}


void Ball::Up() {}
void Ball::Down(){}
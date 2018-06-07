#include "stdafx.h"
#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(b2World* world, double x, double y)
	: MovingObject{}
{
	Load("../MaBibliotheque/paddle.png");

	float SCALE = 30.f;
	myBodyDef.type =b2_kinematicBody;
	myBodyDef.position.Set(x / SCALE, y / SCALE);
	body = world->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(getSizeX() /(SCALE* 2), getSizeY() /(SCALE* 2));

	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	body->CreateFixture(&boxFixtureDef);
	update();
}


PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Up() {
	//body->ApplyLinearImpulseToCenter(b2Vec2(0, -100), 1);
	//body->ApplyForceToCenter(b2Vec2(0, -1000),1);
	if (body->GetLinearVelocity().y >0)
		body->SetLinearVelocity(b2Vec2(0, 0));
	else if (body->GetLinearVelocity().y >-20) 
		body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y - 20));
}
void PlayerPaddle::Down() {
	//body->ApplyLinearImpulseToCenter(b2Vec2(0, 1000), 1);
	//body->ApplyForceToCenter(b2Vec2(0, 1000), 1);
	if (body->GetLinearVelocity().y <0)
		body->SetLinearVelocity(b2Vec2(0, 0));
	else if (body->GetLinearVelocity().y <20) 
		body->SetLinearVelocity(b2Vec2(0, body->GetLinearVelocity().y+20));
}

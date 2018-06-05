#include "stdafx.h"
#include "PlayerPaddle.h"


PlayerPaddle::PlayerPaddle(b2World* world, float x, float y)
	: MovingObject{}
{
	Load("../MaBibliotheque/paddle.png");

	myBodyDef.type =b2_kinematicBody;
	myBodyDef.position.Set(x / SCALE, y / SCALE);
	body = world->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(getSizeX() / 2, getSizeY() / 2);

	boxFixtureDef.shape = &boxShape;
	boxFixtureDef.density = 1;
	body->CreateFixture(&boxFixtureDef);
	update();
}


PlayerPaddle::~PlayerPaddle()
{
}


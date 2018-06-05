#pragma once
#include "MovingObject.h"

class PlayerPaddle 
	: public MovingObject
{
public:
	PlayerPaddle(b2World* world, float x, float y);
	~PlayerPaddle();

private:
	//b2Body * body;
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;
};


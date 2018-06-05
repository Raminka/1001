#pragma once
#include "MovingObject.h"

class Ball
	: public MovingObject
{
public:
	Ball(b2World* world, float x, float y);
	~Ball();

private:
	//b2Body * body;
	b2BodyDef myBodyDef;
	b2FixtureDef myFixtureDef;
};


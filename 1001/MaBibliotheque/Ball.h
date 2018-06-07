#pragma once
#include "MovingObject.h"

class Ball
	: public MovingObject
{
public:
	Ball(b2World* world, double x, double y);
	~Ball();

	void Up() ;
	void Down() ;

private:
	b2BodyDef myBodyDef;
	b2FixtureDef myFixtureDef;
};


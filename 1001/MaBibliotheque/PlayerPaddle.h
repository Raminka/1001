#pragma once
#include "MovingObject.h"

class PlayerPaddle 
	: public MovingObject
{
public:
	PlayerPaddle(b2World* world, double x, double y);
	~PlayerPaddle();

	void Up() ;
	void Down() ; 

private:
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;
};


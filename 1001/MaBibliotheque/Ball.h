#pragma once
#include "MovingObject.h"

class Ball
	: public MovingObject
{
public:
	Ball(b2World* world, double x, double y);
	~Ball();

	void Up(sf::Event event) ;
	void Down(sf::Event event) ;

	void update() override;

private:
	b2BodyDef myBodyDef;
	double vel = 10;
	double coef;
};


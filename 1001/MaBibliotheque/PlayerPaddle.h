#pragma once
#include "MovingObject.h"

class PlayerPaddle 
	: public MovingObject
{
public:
	PlayerPaddle(b2World* world, double x, double y);
	~PlayerPaddle();

	void Up(sf::Event event) ;
	void Down(sf::Event event) ;

	void update() override;

private:
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;
};


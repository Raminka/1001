#pragma once
#include "MovingObject.h"

class PlayerPaddle 
	: public MovingObject
{
public:
	PlayerPaddle(b2World* world, double x, double y);
	~PlayerPaddle();

	/*ces deux fonctionnent permettent le deplacement de joueur*/
	void Up(sf::Event event) ;
	void Down(sf::Event event) ;

	/*mise à jour de la position*/
	void update() override;

private:
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;
};


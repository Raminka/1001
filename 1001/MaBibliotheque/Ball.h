#pragma once
#include "MovingObject.h"

class Ball
	: public MovingObject
{
public:
	Ball(b2World* world, double x, double y);
	~Ball();

	/*mise à jour de la position de Ball*/
	void update() override;

private:
	b2BodyDef myBodyDef;

	/*ces deux variables permettent de garder la vitesse constante*/
	double vel = 10;
	double coef;
};


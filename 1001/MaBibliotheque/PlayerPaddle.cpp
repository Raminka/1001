#include "stdafx.h"
#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle(b2World* world, double x, double y)
	: MovingObject{}
{
	Load("../MaBibliotheque/paddle.png");

	myBodyDef.type = b2_kinematicBody; //pour n'est pas étre perturbé par les balls
	myBodyDef.position.Set(x / scale, y / scale);
	body = world->CreateBody(&myBodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(getSizeX() /(scale* 2), getSizeY() /(scale* 2));

	myFixtureDef.shape = &boxShape;
	myFixtureDef.density = 1;
	body->CreateFixture(&myFixtureDef);
	update();

}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Up(sf::Event event) {
	if (event.type == sf::Event::KeyReleased) { 
		if (body->GetLinearVelocity().y < 0) {
			stop();
		}
	}

	if (body->GetPosition().y <=0.55* getSizeY()/scale) {
		stop();
	}
	else if (event.type == sf::Event::KeyPressed) {
		body->SetLinearVelocity(b2Vec2(0,- 20));
	}
}

void PlayerPaddle::Down(sf::Event event) {
	if (event.type == sf::Event::KeyReleased) {
		if (body->GetLinearVelocity().y >0) {
			stop();
		}
	}

	if (body->GetPosition().y >= (limitWindowY - 0.55*getSizeY()) / scale ) {
		stop();
	}else if (event.type == sf::Event::KeyPressed) {
		body->SetLinearVelocity(b2Vec2(0, 20));
	}

}

void PlayerPaddle::update() {
	/*permet d'éviter de sortir de la zone de jeu*/
	if (body->GetPosition().y <= 0.55*getSizeY() / scale && body->GetLinearVelocity().y<0) {
		stop();
	} else if (body->GetPosition().y >=(limitWindowY -0.55*getSizeY()) / scale && body->GetLinearVelocity().y>0) {
		stop();
	}

	MovingObject::update();
}

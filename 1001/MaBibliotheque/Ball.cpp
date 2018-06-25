#include "stdafx.h"
#include "Ball.h"
#include <math.h>


Ball::Ball(b2World* world, double x, double y)
	: MovingObject{}
{
	Load("../MaBibliotheque/ballFeu.png");

	/*ajoustement de l'image*/
	sprite.setScale(sf::Vector2f(0.30, 0.30)); 

	/*création de body de box2d*/
	myBodyDef.type = b2_dynamicBody;
	myBodyDef.position.Set(x / scale, y / scale);
	body = (world->CreateBody(&myBodyDef));

	b2CircleShape circleShape;
	circleShape.m_radius = 0.85*getSizeX() / (scale*2)	; //0.85 lié au countour de l'image

	myFixtureDef.density = 1;
	myFixtureDef.restitution = 1;//rebondissement au max
	myFixtureDef.shape = &circleShape; 
	myFixtureDef.friction = 0;
	body->CreateFixture(&myFixtureDef);

	/*initialisation du mouvement vers le centre */
	if (x < 200) {
		body->ApplyForce(b2Vec2(600, 0), b2Vec2(0, 0), true);
	}
	else {
		body->ApplyForce(b2Vec2(-600, 0), b2Vec2(0, 0), true);
	}

	update();
}


Ball::~Ball()
{
}


void Ball::update() {

	MovingObject::update();

	/*les calculs suivantes permettent de garder la vitesse constante de la balle*/
	coef = std::sqrt(std::pow(body->GetLinearVelocity().x, 2) + std::pow(body->GetLinearVelocity().y, 2));
	if (coef != 0) {
		/*
		if (std::abs(body->GetLinearVelocity().x )<= 0.02*vel) { //si le mouvement de la balle est verticale 
			if (body->GetPosition().x * scale < limitWindowX / 2) { //permet de rediriger la balle vers le centre
				body->SetLinearVelocity(b2Vec2(0.1*std::abs(body->GetLinearVelocity().y*vel) / coef, 0.9*body->GetLinearVelocity().y*vel / coef));
			}
			else {
				
				body->SetLinearVelocity(b2Vec2(-0.1*std::abs(body->GetLinearVelocity().y*vel )/ coef, 0.9*body->GetLinearVelocity().y*vel / coef));
			}
		}else body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x*vel / coef, body->GetLinearVelocity().y*vel / coef));
		*/
		body->SetLinearVelocity(b2Vec2(body->GetLinearVelocity().x*vel / coef, body->GetLinearVelocity().y*vel / coef));
	}
}
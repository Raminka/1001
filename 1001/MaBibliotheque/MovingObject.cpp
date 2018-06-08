#include "stdafx.h"
#include "MovingObject.h"

MovingObject::MovingObject()
	: isLoaded ( false )
{	
}

MovingObject::~MovingObject()
{
}


void MovingObject::Load(std::string filename1) {
	if (image.loadFromFile(filename1) == false)
	{
		filename = "";
		isLoaded = false;
	}
	else
	{
		filename = filename1;
		image.setSmooth(true);
		sprite.setTexture(image);
		isLoaded = true;
	}

	
}

void MovingObject::Draw(sf::RenderWindow & window) {
	if (isLoaded) {
		window.draw(sprite);
	}
}

float MovingObject::getSizeX() {
	return image.getSize().x;
}

float MovingObject::getSizeY() {
	return image.getSize().y;
}

void MovingObject::update() {
	float SCALE = 30.f;
	b2Vec2 pos = body->GetPosition();
	sprite.setPosition( pos.x*SCALE-getSizeX()/2,pos.y*SCALE-getSizeY()/2);
}

void MovingObject::stop() {
	body->SetLinearVelocity(b2Vec2(0, 0));
}

double MovingObject::getPositonX() {
	float scale = 30.f;
	return body->GetPosition().x*scale;
}
double MovingObject::getPositonY() {
	float scale = 30.f;
	return body->GetPosition().y*scale;
}
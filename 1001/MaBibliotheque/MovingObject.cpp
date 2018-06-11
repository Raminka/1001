#include "stdafx.h"
#include "MovingObject.h"
#include <iostream>

MovingObject::MovingObject()
	: isLoaded(false)
	, limitWindowY(0)
	, limitWindowX(0)
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
	limitWindowY = window.getSize().y;
	limitWindowX = window.getSize().x;
}

void MovingObject::update() {
	b2Vec2 pos = body->GetPosition();
	sprite.setPosition(pos.x*scale - getSizeX() / 2, pos.y*scale - getSizeY() / 2);
}

void MovingObject::stop() {
	body->SetLinearVelocity(b2Vec2(0, 0));
}

void MovingObject::clear() {
	body->DestroyFixture(body->GetFixtureList());
	body->GetWorld()->DestroyBody(body);
}

float MovingObject::getSizeX() const{
	return image.getSize().x*sprite.getScale().x;
}

float MovingObject::getSizeY()const {
	return image.getSize().y*sprite.getScale().y;
}

double MovingObject::getPositionX() const{
	return body->GetPosition().x*scale;
}
double MovingObject::getPositionY() const {
	return body->GetPosition().y*scale;
}

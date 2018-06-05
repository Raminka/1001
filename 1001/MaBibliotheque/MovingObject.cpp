#include "stdafx.h"
#include "MovingObject.h"
#include <iostream>

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
		sprite.setTexture(image);
		isLoaded = true;
	}

	
}

void MovingObject::Draw(sf::RenderWindow & window) {
	if (isLoaded) {
		window.draw(sprite);
	}
}

//initialisation
void MovingObject::SetPosition(float x, float y) {
	if (isLoaded) {
		sprite.setPosition(body->GetPosition().x*SCALE, body->GetPosition().y*SCALE);
	}
}

float MovingObject::getSizeX() {
	return image.getSize().x;
}

float MovingObject::getSizeY() {
	return image.getSize().y;
}

void MovingObject::update() {
	//std::cout << "%d" <<body->GetPosition().x<<"\n";
	b2Vec2 pos = body->GetPosition();
	sprite.setPosition( pos.x*SCALE,pos.y*SCALE);
	std::cout << "x " << sprite.getPosition().x << " " << pos.x*SCALE << "\n";
}
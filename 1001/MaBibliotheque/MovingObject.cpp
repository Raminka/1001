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
		sprite.setTexture(image);
		isLoaded = true;
	}
}

void MovingObject::Draw(sf::RenderWindow & window) {
	if (isLoaded) {
		window.draw(sprite);
	}
}

void MovingObject::SetPosition(float x, float y) {
	if (isLoaded) {
		sprite.setPosition(x, y);
	}
}

float MovingObject::getSizeX() {
	return image.getSize().x;
}

float MovingObject::getSizeY() {
	return image.getSize().y;
}
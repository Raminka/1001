#pragma once
#include <Box2D\Box2D.h>
#include <string>
#include <SFML/Graphics.hpp>
const float SCALE = 30.f;


class MovingObject
{
public:
	MovingObject();
	virtual ~MovingObject(void) =0;

	virtual void Load(std::string filename1);
	virtual void Draw(sf::RenderWindow & window);
	
	virtual void SetPosition(float x, float y);

	virtual float getSizeX();
	virtual float getSizeY();


	void update();

	b2Body * body=NULL;
	//b2World * world;
private:
	sf::Sprite sprite;
	sf::Texture image;
	std::string filename;
	bool isLoaded;
};


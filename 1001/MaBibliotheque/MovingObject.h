#pragma once
#include <Box2D\Box2D.h>
#include <string>
#include <SFML/Graphics.hpp>

class MovingObject
{
public:
	MovingObject();
	virtual ~MovingObject(void) =0;

	virtual void Load(std::string filename1);
	virtual void Draw(sf::RenderWindow & window);

	virtual float getSizeX();
	virtual float getSizeY();


	void update();

	virtual	void Up()=0;
	virtual	void Down() = 0;
	void stop();

	b2Body * body=NULL;

	double getPositonX();
	double getPositonY();

private:
	sf::Sprite sprite;
	sf::Texture image;
	std::string filename;
	bool isLoaded;
};


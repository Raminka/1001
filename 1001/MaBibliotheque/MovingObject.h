#pragma once
#include <string>
#include <SFML/Graphics.hpp>
class MovingObject
{
public:
	MovingObject();
	~MovingObject();

	virtual void Load(std::string filename1);
	virtual void Draw(sf::RenderWindow & window);
	
	virtual void SetPosition(float x, float y);

	virtual float getSizeX();
	virtual float getSizeY();

private:
	sf::Sprite sprite;
	sf::Texture image;
	std::string filename;
	bool isLoaded;
};


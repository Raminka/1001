#pragma once
#include <Box2D\Box2D.h>
#include <string>
#include <SFML/Graphics.hpp>

class MovingObject
{
public:
	MovingObject();
	virtual ~MovingObject(void) =0;

	virtual void Draw(sf::RenderWindow & window) ; //affichage SFML

	virtual void update()=0; //mise à jour de position
	void clear(); //supprime le body
	
	virtual	void Up(sf::Event event)=0; 
	virtual	void Down(sf::Event event) = 0;
	void stop();

	/*getteurs*/
	virtual float getSizeX()const;
	virtual float getSizeY()const;
	double getPositionX() const;
	double getPositionY()const;

protected:

	virtual void Load(std::string filename1);//chargement d'image

	b2FixtureDef myFixtureDef;
	/*données d'élément*/
	sf::Sprite sprite;
	b2Body * body = NULL;
	float scale = 30.f;
	double limitWindowY;
	double limitWindowX;

private:
	sf::Texture image;
	std::string filename;
	bool isLoaded;
};


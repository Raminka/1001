#pragma once
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

/*la déclaration de la taille standard de l'objet*/
static const unsigned int tailleX(12);
static const unsigned int tailleY(65);

class Obstacle
{
public:
	Obstacle(double X, double Y, b2World* world, sf::RenderWindow & window, double dimx,double dimy);
	virtual ~Obstacle();

	/*affichage sfml*/
	virtual void Draw(sf::RenderWindow & window) = 0;

	virtual void startContact() = 0;//si l'objet est touché -> depend de type d'obstacle

	virtual void clear();

	/*getteurs*/
	double getX() const;
	double getY() const;
	double getDimX() const;
	double getDimY() const;
	
	/*les actions possibles après le contact*/
	enum ObstacleAction{toDelete,stopGame,switchLight,nothing};
	ObstacleAction obstacleAction;

protected:
	/*position d'obstacle*/
	double x;
	double y;
	/*conversion entre box2d et sfml*/
	float SCALE = 30.f;
	/*dimensions d'obstacle*/
	double dimX;
	double dimY;
	/*definition de body*/
	b2Body* staticBody = NULL;
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;

	bool m_contact; //est ce qu'il ya contact
};


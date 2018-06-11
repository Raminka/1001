#pragma once
#include "pugixml.hpp"
#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>

static const unsigned int tailleX(10);
static const unsigned int tailleY(50);

class Obstacle
{
public:
	Obstacle(double X, double Y, b2World* world, sf::RenderWindow & window, double dimx,double dimy);

	virtual void Draw(sf::RenderWindow & window) = 0;

	virtual void startContact() = 0;//si l'objet est touché

	void clear();

	double getX() const;
	double getY() const;
	double getDimX() const;
	double getDimY() const;

//	bool touched; //objet touché ou pas

	enum ObstacleAction{toDelete,stopGame,switchLight,nothing};
	ObstacleAction obstacleAction;

protected:
	double x;
	double y;
	float SCALE = 30.f;

	double dimX;
	double dimY;

	b2Body* staticBody = NULL;
	b2BodyDef myBodyDef;
	b2FixtureDef boxFixtureDef;

	bool m_contact; //est ce qu'il ya contact
};


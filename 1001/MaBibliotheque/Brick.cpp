#include "stdafx.h"
#include "Brick.h"

Brick::Brick(pugi::xml_node node, b2World *world, sf::RenderWindow & window)
	: Obstacle{ node.attribute("x").as_double()*tailleX,node.attribute("y").as_double()*tailleY,world,window,tailleX,tailleY }
{
}

void Brick::Draw(sf::RenderWindow & window) {	
	/*si l'objet est touché alors on déclare l'action de supprimer le Brick au prochain tour*/
	if (m_contact)
	{
		obstacleAction = toDelete;
		clear();
	}
	/*sinon on trace l'objet*/
	else {
		sf::RectangleShape rect(sf::Vector2f(dimX - 0.5, dimY - 0.5));
		rect.setPosition(staticBody->GetPosition().x*SCALE - dimX / 2, staticBody->GetPosition().y*SCALE - dimY / 2);
		rect.setFillColor(sf::Color(255, 255, 255));
		window.draw(rect);
	}
}

void Brick::startContact() { m_contact = true; }
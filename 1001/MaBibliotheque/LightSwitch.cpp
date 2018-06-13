#include "stdafx.h"
#include "LightSwitch.h"



LightSwitch::LightSwitch(pugi::xml_node node, b2World *world, sf::RenderWindow & window)
	: Obstacle{ node.attribute("x").as_double()*tailleX,node.attribute("y").as_double()*tailleY,world,window,3*tailleX,tailleY }
{
}

void LightSwitch::Draw(sf::RenderWindow & window) {
		sf::RectangleShape rect(sf::Vector2f(dimX - 0.5, dimY - 0.5));
		rect.setPosition(staticBody->GetPosition().x*SCALE - dimX / 2, staticBody->GetPosition().y*SCALE - dimY / 2);
		rect.setFillColor(sf::Color::Red);
		window.draw(rect);
		/*l'affichage est appelé après la mise à jour donc la variable est traitée et 
		risque de changer à l'infini le mode de jeu si on la change pas*/
		obstacleAction = nothing;
}

void LightSwitch::startContact() {
	if (obstacleAction == nothing) {
		/*indique qu'il faut changer le mode de jeu*/
		obstacleAction = switchLight;
	}
}
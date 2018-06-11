#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>




class button
{
public:
	enum MenuAction { Nothing, Exit, PlayLVL1, PlayLVL2 };
	button(sf::RenderWindow& window, double centerX, double centerY, double dim, std::string label, MenuAction action, double proportionLettre);
	~button();
	double getCentreX() const;
	double getCentreY() const;
	double getDim() const;
	MenuAction action;
	void Draw(sf::RenderWindow& window);

private:
	double centreX;
	double centreY;
	double dim;
	std::string label;
	sf::ConvexShape convex1;
	sf::ConvexShape convex2;
	sf::Text text;
	sf::Font font;

	/*permet d'ajouster le text à l'affichage de button*/
	double proportionLettre;
};


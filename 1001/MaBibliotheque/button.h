#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>




class button
{
public:
	/*l'utilisateur choisi l'action à faire. Pour le moment on a que 2 niveaux*/
	enum MenuAction { Nothing, Exit, PlayLVL1, PlayLVL2 };

	/*constructeur de button*/
	button(sf::RenderWindow& window, double centerX, double centerY, double dim, std::string label, MenuAction action, double proportionLettre);
	~button();

	/*les getteurs permettent au MainMenu de connaître la position et la dimension 
	de button àfin de savoir sur quel button appui l'utilisateur*/
	double getCentreX() const;
	double getCentreY() const;
	double getDim() const;

	/*action associé au button*/
	MenuAction action;

	/*representation SFML du button*/
	void Draw(sf::RenderWindow& window);

private:
	double centreX;
	double centreY;
	double dim;

	/*definition de triangles pour distinguer les deux modes*/
	sf::ConvexShape convexLight;
	sf::ConvexShape convexDark;

	/*nom du button*/
	std::string label;
	/*Text SFML affiché*/
	sf::Text text;
	/*la police à charger*/
	sf::Font font;

	/*permet d'ajouster le text à l'affichage de button*/
	double proportionLettre;
};


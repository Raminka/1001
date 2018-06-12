#include "stdafx.h"
#include "button.h"


button::button(sf::RenderWindow& window, double centreX, double centreY, double dim, std::string label, MenuAction action,double proportionLettre)
	: centreX(centreX)
	, centreY(centreY)
	, dim(dim)
	, label(label)
	,action(action)
	, proportionLettre(proportionLettre)
{
	/*definition de triangle Light*/
	convexLight.setPointCount(3);
	convexLight.setPoint(0, sf::Vector2f(centreX-dim/2, centreY-dim/2));
	convexLight.setPoint(1, sf::Vector2f(centreX+dim/2, centreY-dim/2));
	convexLight.setPoint(2, sf::Vector2f(centreX-dim/2, centreY+dim/2));
	
	/*definition de triangle Dark*/
	convexDark.setPointCount(3);
	convexDark.setPoint(0, sf::Vector2f(centreX + dim/2, centreY + dim/2));
	convexDark.setPoint(1, sf::Vector2f(centreX + dim/2, centreY - dim/2));
	convexDark.setPoint(2, sf::Vector2f(centreX - dim/2, centreY + dim/2));

	/*si le button est Exit alors on a qu'une seule action et donc une seule couleur*/
	if (action == Exit) {
		convexLight.setFillColor(sf::Color(255, 125, 125));
		convexDark.setFillColor(sf::Color(255, 125, 125));
	}
	else { /*sinon chaque triangle a sa couleur propre*/
		convexDark.setFillColor(sf::Color(55, 55, 55));
		convexLight.setFillColor(sf::Color(200, 200, 200));
	}

	
	/*chargement de la police */
	if (!font.loadFromFile("../MaBibliotheque/NORIKEE.ttf"))
	{
		std::cout << "erreur de chargement de police\n";
	}
	
	/*definition de text sur le bouton*/
	text.setFont(font);
	text.setFillColor(sf::Color(255, 0, 0));
	text.setCharacterSize(dim*0.6);
	text.setString(label);
	text.setStyle(sf::Text::Bold);
	text.setPosition(centreX - dim * proportionLettre, centreY - dim * 0.35);
}

void button::Draw(sf::RenderWindow& window) {
	/*affichage des éléments de button*/
	window.draw(convexLight);
	window.draw(convexDark);
	window.draw(text);
}

button::~button()
{
}

/*getteurs*/
double button::getCentreX() const {
	return centreX;
}
double button::getCentreY() const {
	return centreY;
}
double button::getDim() const {
	return dim;
}

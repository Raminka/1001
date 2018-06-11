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
	convex1.setPointCount(3);
	convex1.setPoint(0, sf::Vector2f(centreX-dim/2, centreY-dim/2));
	convex1.setPoint(1, sf::Vector2f(centreX+dim/2, centreY-dim/2));
	convex1.setPoint(2, sf::Vector2f(centreX-dim/2, centreY+dim/2));
	

	convex2.setPointCount(3);
	convex2.setPoint(0, sf::Vector2f(centreX + dim/2, centreY + dim/2));
	convex2.setPoint(1, sf::Vector2f(centreX + dim/2, centreY - dim/2));
	convex2.setPoint(2, sf::Vector2f(centreX - dim/2, centreY + dim/2));

	if (action == Exit) {
		convex1.setFillColor(sf::Color(255, 125, 125));
		convex2.setFillColor(sf::Color(255, 125, 125));

	}
	else {
		convex2.setFillColor(sf::Color(55, 55, 55));
		convex1.setFillColor(sf::Color(200, 200, 200));
	}

	
	
	if (!font.loadFromFile("../MaBibliotheque/NORIKEE.ttf"))
	{
		std::cout << "erreur de chargement de police\n";
	}
	
	text.setFont(font);
	text.setFillColor(sf::Color(255, 0, 0));
	text.setCharacterSize(dim*0.6);
	
	text.setString(label);
	text.setStyle(sf::Text::Bold);
	text.setPosition(centreX - dim * proportionLettre, centreY - dim * 0.35);

	

}

void button::Draw(sf::RenderWindow& window) {
	window.draw(convex1);
	window.draw(convex2);
	window.draw(text);
}

button::~button()
{
}


double button::getCentreX() const {
	return centreX;
}
double button::getCentreY() const {
	return centreY;
}
double button::getDim() const {
	return dim;
}

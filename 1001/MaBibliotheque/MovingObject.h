#pragma once
#include <Box2D\Box2D.h>
#include <string>
#include <SFML/Graphics.hpp>

class MovingObject
{
public:
	MovingObject();
	virtual ~MovingObject(void) ;

	virtual void Draw(sf::RenderWindow & window) ; //affichage SFML

	virtual void update()=0; //mise à jour de position
	void clear(); //supprime le body
	
	/*le mouvement de joueur en fonction de commandes de joueurs
	Fonction est définie que pour les PlayerPaddles*/
	virtual	void Up(sf::Event event); 
	virtual	void Down(sf::Event event) ;
	void stop();

	/*getteurs*/
	double getPositionX() const;
	double getPositionY()const;

protected:

	 void Load(std::string filename1);//chargement d'image

	/*données d'élément*/
	sf::Sprite sprite;
	b2Body * body = NULL;
	b2FixtureDef myFixtureDef;
	float scale = 30.f; //permet le passage entre SFML et box2D
	double limitWindowY; 
	double limitWindowX;
	
	/*calcule de la taille dobjet en fonction de l'image*/
	double getSizeX()const;
	double getSizeY()const;

private:
	sf::Texture image;
	std::string filename;
	bool isLoaded;
};


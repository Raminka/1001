#include "stdafx.h"
#include "ObjectManager.h"
#include <iostream>



ObjectManager::ObjectManager()
	: Stop(false)
	, darkMode(false)
	, radiusMax(1000)
	,radiusMin(120)
	, radiusCircle(radiusMax)
{

	target.create(1280, 960);
	for (int i = 0; i < 4; i++) {
		sf::CircleShape circle(radiusCircle);
		lights.push_back(circle);
	}
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddMovingObject(std::string name, MovingObject* gameObject)
{
	movingObjects.insert(std::pair<std::string, MovingObject*>(name, std::move(gameObject)));
}

void ObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	for (auto & object : movingObjects) {
		object.second->Draw(renderWindow);
	}
	for (auto & obstacle : obstacles) {
		obstacle->Draw(renderWindow);
	}
}

void ObjectManager::Update(sf::RenderWindow& window) {
	for (auto & object : movingObjects) {
		if (Stop) object.second->stop();//on arrete les movingObjects quand le jeu s'arrete
		object.second->update();
	}
	for (int i = 0; i < obstacles.size();i++) {
		if (obstacles[i]->obstacleAction==Obstacle::toDelete) { //si les bricks sont touchés
			obstacles.erase(obstacles.begin() + i); //alors on supprime les bricks
			if (i >= 1) {
				i--;
			}
		}
		else if (obstacles[i]->obstacleAction == Obstacle::stopGame) { //si les bricks sont touchés
			Stop = true;
		}
		else if (obstacles[i]->obstacleAction == Obstacle::switchLight) { //si les bricks sont touchés
			if (darkMode) { darkMode = false; }
			else { darkMode = true;}

		}
	}
	DrawAll(window); 
	
	/*si mode Dark est activé*/
	if (darkMode) {
		/*on retrecie l'écran au fur à mesure*/
		if (radiusCircle > radiusMin) {
			if (radiusCircle > 800) {
				radiusCircle = 600;
			}else 
			radiusCircle  -= 10;
		}
		target.clear(sf::Color(0, 0, 0, 255));
		int i = 0;
		/*définition de cercles lumineux*/
		for (auto & object : movingObjects) {//on centre chaque cercle sur les objets en mouvements
			lights[i].setRadius(radiusCircle);
			lights[i].setPosition(sf::Vector2f(object.second->getPositionX() - lights[i].getRadius(), object.second->getPositionY() - lights[i].getRadius()));
			target.draw(lights[i], sf::BlendNone);
			i++;
		}
		target.display();
		window.draw(sf::Sprite(target.getTexture()));
	}	
	else {
		/*on continue à tracer target qui si le rayon n'est pas maximal*/
		if (radiusCircle < radiusMax) {
			radiusCircle += 10;

			target.clear(sf::Color(0, 0, 0, 255));
			int i = 0;
			for (auto & object : movingObjects) {//on centre chaque cercle sur les objets en mouvements
				lights[i].setRadius(radiusCircle);
				lights[i].setPosition(sf::Vector2f(object.second->getPositionX() - lights[i].getRadius(), object.second->getPositionY() - lights[i].getRadius()));
				target.draw(lights[i], sf::BlendNone);
				i++;
			}
			target.display();
			window.draw(sf::Sprite(target.getTexture()));
		}
	}
		
}

void ObjectManager::initObjects(pugi::xml_node node, b2World *world, sf::RenderWindow & window) {
	/*walls*/
	obstacles.push_back(std::make_unique<Wall>(2 - ((double)window.getSize().x / 2), 0, world, window, 4, window.getSize().y, "Left"));
	obstacles.push_back(std::make_unique<Wall>(((double)window.getSize().x / 2), 0, world, window,4 , window.getSize().y, "Right"));
	obstacles.push_back(std::make_unique<Wall>(0, 2 - ((double)window.getSize().y / 2), world, window, window.getSize().x, 4, "Up"));
	obstacles.push_back(std::make_unique<Wall>(0, ((double)window.getSize().y / 2), world, window, window.getSize().x, 4, "Down"));

	/*création des obstacles à partir de xml*/
	for (auto child : node.children()) {
		if ((std::string) child.name() == "Brick") {
			obstacles.push_back(std::make_unique<Brick>(child, world,window));
		}
		if ((std::string) child.name() == "Rock") {
			obstacles.push_back(std::make_unique<Rock>(child, world,window));
		}
		if ((std::string) child.name() == "LightSwitch") {
			obstacles.push_back(std::make_unique<LightSwitch>(child, world, window));
		}
	}

	/*initialisation de la target lorsque  le mode dark est appelé*/
	target.clear(sf::Color(0, 0, 0, 255));
	for (int i = 0; i < 4; i++) {
		lights[i].setFillColor(sf::Color(255, 255, 255, 1));
		lights[i].setPosition(0, 0);
	}
	
	/*creation des objets mobiles*/
	PlayerPaddle *player1 = new PlayerPaddle(world, 30, (window.getSize().y) / 2);
	PlayerPaddle *player2 = new PlayerPaddle(world, window.getSize().x - 30, (window.getSize().y) / 2);
	Ball *ball1 = new Ball{ world,(double)40,(double)(window.getSize().y) / 2 };
	Ball *ball2 = new Ball(world, window.getSize().x - 40, (window.getSize().y) / 2);

	AddMovingObject("player1",player1);
	AddMovingObject("player2", player2);
	AddMovingObject("ball1", ball1);
	AddMovingObject("ball2", ball2);
}


void ObjectManager::handleInput(sf::Event event) {
	if (event.key.code == sf::Keyboard::Up) movingObjects["player2"]->Up(event);
	else if (event.key.code == sf::Keyboard::Down) movingObjects["player2"]->Down(event);
	if (event.key.code == sf::Keyboard::Z)  movingObjects["player1"]->Up(event);
	else if (event.key.code == sf::Keyboard::S) movingObjects["player1"]->Down(event);
}

void ObjectManager::clear() {
	for (auto & object : movingObjects) {
		object.second->clear();
	} 
	movingObjects.clear();

	for (auto & obstacle : obstacles) {
		obstacle->clear();
	}
	obstacles.clear();
	

	/*remise à zero des variables*/
	Stop = false;
	darkMode = false;
	radiusCircle = radiusMax;
}
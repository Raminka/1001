#include "stdafx.h"
#include "ObjectManager.h"



ObjectManager::ObjectManager()
	:Stop(false)
{
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
	for (int i = 0; i <4; i++) {
		if (obstacles[i]->toDelete) {
			Stop = true;;
		}
	}
	for (auto & object : movingObjects) {
		if (Stop) object.second->stop();
		object.second->update();
	}
	for (int i = 4; i < obstacles.size();i++) {
		if (obstacles[i]->toDelete) {
			obstacles.erase(obstacles.begin() + i);
		}
	}
	DrawAll(window);
	
	target.clear(sf::Color(0, 0, 0, 255));
	int i = 0;
	for (auto & object : movingObjects) {
		lights[i].setPosition(sf::Vector2f(object.second->getPositonX()-lights[i].getRadius(),object.second->getPositonY() - lights[i].getRadius()));
		target.draw(lights[i], sf::BlendNone);
		i++;
	}
	target.display();
	window.draw(sf::Sprite(target.getTexture()));
	
}


void ObjectManager::initObstacles(pugi::xml_node node, b2World *world, sf::RenderWindow & window) {
	/*walls*/
	
	obstacles.push_back(std::make_unique<Wall>(2-((double)window.getSize().x/2),0, world, window, 2, window.getSize().y,"Left"));//gauche
	obstacles.push_back(std::make_unique<Wall>(((double)window.getSize().x/2 ), 0, world, window, 2, window.getSize().y,"Right"));//droite
	obstacles.push_back(std::make_unique<Wall>(0, 2 - ((double)window.getSize().y / 2), world, window,  window.getSize().x,2, "Up"));//haut
	obstacles.push_back(std::make_unique<Wall>(0, ((double)window.getSize().y / 2), world, window, window.getSize().x, 2,"Down"));//bas

	
	for (auto child : node.children()) {
		if ((std::string) child.name() == "Brick") {
			obstacles.push_back(std::make_unique<Brick>(child, world,window));
		}
		if ((std::string) child.name() == "Rock") {
			obstacles.push_back(std::make_unique<Rock>(child, world,window));
		}
	}


	target.create(1024,768);
	target.clear(sf::Color(0, 0, 0, 255));
	for (int i = 0; i < 4;i++) {
		sf::CircleShape circle(120);
		circle.setFillColor(sf::Color(255, 255, 255, 1));
		circle.setPosition(i * 10, i * 20);
		target.draw(circle, sf::BlendNone);
		lights.push_back(circle);
	}
	target.display();
	window.draw(sf::Sprite(target.getTexture()));
	
}

void ObjectManager::handleInput(sf::Event event) {
	
	if (event.key.code == sf::Keyboard::Up) movingObjects["player2"]->Up();
	else if (event.key.code == sf::Keyboard::Down) movingObjects["player2"]->Down();
	if (event.key.code == sf::Keyboard::Z)  movingObjects["player1"]->Up();
	else if (event.key.code == sf::Keyboard::S) movingObjects["player1"]->Down();
}
#include "stdafx.h"
#include "ObjectManager.h"



ObjectManager::ObjectManager()
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
	for (auto & object : movingObjects) {
		object.second->update();
	}
	DrawAll(window);
}


void ObjectManager::initObstacles(pugi::xml_node node, b2World *world, sf::RenderWindow & window) {
	/*walls*/
	
	obstacles.push_back(std::make_unique<Wall>(2-((double)window.getSize().x/2),0, world, window, 2, window.getSize().y));//gauche
	obstacles.push_back(std::make_unique<Wall>(((double)window.getSize().x/2 ), 0, world, window, 2, window.getSize().y));//droite
	obstacles.push_back(std::make_unique<Wall>(0, 2 - ((double)window.getSize().y / 2), world, window,  window.getSize().x,2));//haut
	obstacles.push_back(std::make_unique<Wall>(0, ((double)window.getSize().y / 2), world, window, window.getSize().x, 2));//bas

	
	for (auto child : node.children()) {
		if ((std::string) child.name() == "Brick") {
			obstacles.push_back(std::make_unique<Brick>(child, world,window));
		}
		if ((std::string) child.name() == "Rock") {
			obstacles.push_back(std::make_unique<Rock>(child, world,window));
		}
	}
}

void ObjectManager::handleInput(sf::Event event) {
	
	if (event.key.code == sf::Keyboard::Up) movingObjects["player2"]->Up();
	else if (event.key.code == sf::Keyboard::Down) movingObjects["player2"]->Down();
	if (event.key.code == sf::Keyboard::Z)  movingObjects["player1"]->Up();
	else if (event.key.code == sf::Keyboard::S) movingObjects["player1"]->Down();
}
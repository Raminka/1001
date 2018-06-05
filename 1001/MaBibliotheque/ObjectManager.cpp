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

/*
MovingObject* ObjectManager::GetMovingObject(std::string name) const
{
	for (auto & results : movingObjects) {
		if (results.first==name) {
			return results.second;
		}
	}
}*/

void ObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
	for (auto & object : movingObjects) {
		object.second->Draw(renderWindow);
	}
	
}

void ObjectManager::Update(sf::RenderWindow& window) {
	for (auto & object : movingObjects) {
		object.second->update();
	}
	DrawAll(window);
}
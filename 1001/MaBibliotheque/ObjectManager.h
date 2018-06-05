#pragma once
#include "MovingObject.h"
//#include "Obstacle.h"
#include <iostream>
#include <memory>

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void AddMovingObject(std::string name, MovingObject* movingObject);
	//void AddObstacle(std::string name, Obstacle* movingObject);
//	MovingObject* GetMovingObject(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);

private:
	std::map<std::string, std::unique_ptr<MovingObject>> movingObjects;
};
#pragma once
#include "MovingObject.h"
#include "Obstacle.h"
#include <iostream>
#include <memory>
#include "Rock.h"
#include "Brick.h"
#include "Wall.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void initObstacles(pugi::xml_node node, b2World *world, sf::RenderWindow & window);

	void AddMovingObject(std::string name, MovingObject* movingObject);
	
	void Update(sf::RenderWindow& window);
	
	void handleInput(sf::Event event);

	bool Stop;

private:
	std::map<std::string, std::unique_ptr<MovingObject>> movingObjects;
	std::vector<std::unique_ptr<Obstacle>> obstacles;

	void DrawAll(sf::RenderWindow& renderWindow);

	std::vector<sf::CircleShape> lights;
	sf::RenderTexture target;
};
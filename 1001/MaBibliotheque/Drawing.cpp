#include "stdafx.h"
#include "Drawing.h"
#include <iostream>

Drawing::Drawing() {

}

Drawing::Drawing(pugi::xml_node node,b2World *world)
{
	for (auto child : node.children()) {
		if ((std::string) child.name() == "Brick") {
			obstacles.push_back(std::make_unique<Brick>(child,world));
		}
		if ((std::string) child.name() == "Rock") {
			obstacles.push_back(std::make_unique<Rock>(child,world));
		}
	}
}

void Drawing::update(pugi::xml_node node, b2World *world) {
	for (auto child : node.children()) {
		if ((std::string) child.name() == "Brick") {
			obstacles.push_back(std::make_unique<Brick>(child,world));

		}
		if ((std::string) child.name() == "Rock") {
			obstacles.push_back(std::make_unique<Rock>(child,world));
		}
	}
}

void Drawing::Draw(sf::RenderWindow & window) {
	for (auto & obstacle : obstacles) {
		obstacle->Draw(window);
	}
}


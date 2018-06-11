#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>
#include <pugixml.hpp>
#include "button.h"
#include <memory>

class MainMenu
{

public:
	MainMenu();
	~MainMenu();
	void create(sf::RenderWindow& window);
	enum ModePlay { Light, Dark };
	struct MainMenuResult {
		button::MenuAction action;
		ModePlay mode;
	};
	MainMenu::MainMenuResult Show(sf::RenderWindow& window);
	void clear();

private:
	MainMenu::MainMenuResult GetMenuResponse(sf::RenderWindow& window);
	MainMenu::MainMenuResult HandleClick(int x, int y);
	std::list<std::unique_ptr<button>> menuItems;
	pugi::xml_node nodeLVL;
};
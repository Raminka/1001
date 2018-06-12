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
	/*creation des boutons*/
	void create(sf::RenderWindow& window);

	/*le mode de jeu choisie*/
	enum ModePlay { Light, Dark };
	struct MainMenuResult {
		button::MenuAction action;
		ModePlay mode;
	};

	/*affishage SFML*/
	MainMenu::MainMenuResult Show(sf::RenderWindow& window);

	/*supprime les bouttons*/
	void clear();

private:
	/*en attente de choix correct de la part d'utilisateur, renvoie le resultat de HandleClick*/
	MainMenu::MainMenuResult GetMenuResponse(sf::RenderWindow& window);

	/*renvoie le resultat en fonction où l'utilisateur a appuyé*/
	MainMenu::MainMenuResult HandleClick(int x, int y);

	/*la liste des bouttons*/
	std::list<std::unique_ptr<button>> menuItems;

	/*Text SFML affiché*/
	sf::Text text;
	/*la police à charger*/
	sf::Font font;
};
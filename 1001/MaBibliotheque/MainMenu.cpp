#include "stdafx.h"
 #include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(){
}
MainMenu::~MainMenu(){}

void MainMenu::create(sf::RenderWindow& window) {
	/*deffinition des 3 boutons*/
	menuItems.push_back(std::make_unique<button>(window, 375, 440, 375, "I", button::PlayLVL1, 0.05));
	menuItems.push_back(std::make_unique<button>(window, window.getSize().x - 375, 440, 375, "II", button::PlayLVL2, 0.15));
	menuItems.push_back(std::make_unique<button>(window, window.getSize().x / 2, window.getSize().y - 180, 250, "X", button::Exit, 0.2));

	/* le nom de jeu */
	/*chargement de la police */
	if (!font.loadFromFile("../MaBibliotheque/NORIKEE.ttf"))
	{
		std::cout << "erreur de chargement de police\n";
	}
	/*definition de text */
	text.setFont(font);
	text.setFillColor(sf::Color(255, 0, 0));
	text.setCharacterSize(100);
	text.setString("IOOI");
	text.setStyle(sf::Text::Bold);
	text.setPosition(window.getSize().x/2-100,50);
}

 MainMenu::MainMenuResult MainMenu::Show(sf::RenderWindow& window)
 {
	 /*on vide la fenetre d'avant*/
	 window.clear();

	 /*affichage de chaque boutton*/
	 for (auto & item : menuItems) {
		 item->Draw(window);
	 }

	 /*affichage de titre*/
	window.draw(text);

	window.display();
	return GetMenuResponse(window);
}

 MainMenu::MainMenuResult MainMenu::HandleClick(int x, int y)
 {
	//std::list<button>::iterator it;
	for (auto it = menuItems.begin(); it != menuItems.end(); it++)
	{
		/*verification si le click a eu lieu sur un des buttons*/
		if ((*it)->getCentreY() - (*it)->getDim() / 2 < y
			&& (*it)->getCentreY() + (*it)->getDim() / 2 > y
			&& (*it)->getCentreX() - (*it)->getDim() / 2 < x
			&& (*it)->getCentreX() + (*it)->getDim() / 2 > x) {
			/*permet de savoir si le mode Light ou Dark a été choisi*/
			if (x + y < (*it)->getCentreY()+ (*it)->getCentreX())
				return  { (*it)->action, Light };
			else return { (*it)->action, Dark };
		}
	}	
	return { button::Nothing, Light };
}

 MainMenu::MainMenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
 {
	sf::Event menuEvent;

	while (true)
	{
		while (window.pollEvent(menuEvent))
		{
			if (menuEvent.type == sf::Event::MouseButtonPressed)
		    {
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
		    }
		    if (menuEvent.type == sf::Event::Closed)
		    {
				return { button::Exit,Light };
			}
		}
	}
}


 void MainMenu::clear() {
	 menuItems.clear();
 }
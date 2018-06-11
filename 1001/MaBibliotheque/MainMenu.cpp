#include "stdafx.h"
 #include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(){
}
MainMenu::~MainMenu(){}

void MainMenu::create(sf::RenderWindow& window) {
	menuItems.push_back(std::make_unique<button>(window, 300, 250, 300, "I", button::PlayLVL1, 0.05));
	menuItems.push_back(std::make_unique<button>(window, window.getSize().x - 300, 250, 300, "II", button::PlayLVL2, 0.15));
	menuItems.push_back(std::make_unique<button>(window, window.getSize().x / 2, window.getSize().y - 250, 200, "X", button::Exit, 0.2));
}

 MainMenu::MainMenuResult MainMenu::Show(sf::RenderWindow& window)
 {

	 window.clear();
	 for (auto & item : menuItems) {
		 item->Draw(window);
	 }

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
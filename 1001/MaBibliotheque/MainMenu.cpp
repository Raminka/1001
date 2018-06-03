#include "stdafx.h"
 #include "MainMenu.h"

 MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
 {
	

	//Play menu item coordinates
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;
	
	//Exit menu item coordinates
	MenuItem exitButton;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.rect.top = 383;
	exitButton.rect.height = 177;
	exitButton.action = Exit;
	
	menuItems.push_back(playButton);
	menuItems.push_back(exitButton);
	
	sf::RectangleShape rectPlay;
	rectPlay.setPosition(playButton.rect.left, playButton.rect.top);
	rectPlay.setFillColor(sf::Color(125, 125, 125));
	rectPlay.setSize(sf::Vector2f(playButton.rect.width,playButton.rect.height ));
	 
	sf::RectangleShape rectExit;
	rectExit.setPosition(exitButton.rect.left, exitButton.rect.top);
	rectExit.setFillColor(sf::Color(255, 125, 125));
	rectExit.setSize(sf::Vector2f(exitButton.rect.width, exitButton.rect.height));
	

	window.draw(rectPlay);
	window.draw(rectExit);
	window.display();
	return GetMenuResponse(window);
}

 MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
 {
	std::list<MenuItem>::iterator it;
	
	for (it = menuItems.begin(); it != menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.top+menuItemRect.height > y
			 && menuItemRect.top < y
			 && menuItemRect.left < x
			 && menuItemRect.width+menuItemRect.width > x)
		 {
		      return (*it).action;
		 }
	}	
	return Nothing;
}

 MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
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
			     return Exit;
			}
		}
	}
}





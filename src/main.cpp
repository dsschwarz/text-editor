#include <iostream>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "helper.h"
#include "KeyHandler.h"

std::vector<int> charArray;

int row = 0;
int col = 0;
sf::Sprite getSprite(int imageNum) {
	int index = hlp::findInKeyCodes(imageNum);
	if(index == -1)
		return sf::Sprite();
	sf::Sprite sprite(hlp::textures[index]);
	sprite.setPosition(col * 20, row * 20);
	return sprite;
}
void drawWindow(sf::RenderWindow* window) {

	row = 0;
	col = 0;
	for(auto& x: charArray) {
		window->draw(getSprite(x));
		row ++;
		if(row > 20) {
			row = 0;
			col ++;
		}
	}
}

int main() {
	hlp::loadImages();
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Text Editor");
	KeyHandler keyHandler(&window, &charArray);

	
	while(window.isOpen()) {
		
		window.display();
		sf::Event event;
		while(window.waitEvent(event)) {
			keyHandler.handleEvents(event);
			window.clear();
			drawWindow(&window);
			window.display();
		}

	}
	return 0;
}
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
void renderChars(sf::RenderWindow* window) {

	row = 0;
	col = 0;
	for (int i = 0; i < charArray.size(); ++i)
	{
		int x = charArray[i];
		window->draw(getSprite(x));

		// If character is NOT a consonant followed by a vowel, advace one space
		if(!((x > hlp::FIRST_CONS) && (i+1 < charArray.size()) && (charArray[i+1] < hlp::FIRST_CONS))) {
			row ++;
			if(row >= 20) {
				row = 0;
				col ++;
			}
		}
	}
}

int main() {
	hlp::loadImages();
	hlp::outputKeyMapping();
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Text Editor");
	KeyHandler keyHandler(&window, &charArray);

	
	while(window.isOpen()) {
		
		window.display();
		sf::Event event;
		while(window.waitEvent(event)) {
			keyHandler.handleEvents(event);
			window.clear();
			renderChars(&window);
			keyHandler.drawCursor(&window);
			window.display();
		}

	}
	return 0;
}
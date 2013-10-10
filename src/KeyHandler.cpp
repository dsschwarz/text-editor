#include "helper.h"
#include "KeyHandler.h"

KeyHandler::KeyHandler(sf::Window* win, std::vector<int>* charArray_p) {
	window = win;
	charArray = charArray_p;
	row = 0;
	column = 0;

}
void KeyHandler::insertChar(int keyCode) {
	charArray->push_back(keyCode);
	// for(auto& x: *charArray)
	// 	std::cout << ' ' << x;
	// std::cout << '\n';
}
void KeyHandler::removeChar() {
	charArray->pop_back();
}
void KeyHandler::handleEvents(sf::Event event) {
	if (event.type == sf::Event::Closed) {
		window->close();
	}
	else if(event.type == sf::Event::KeyPressed) {
		if(event.key.code == sf::Keyboard::Escape)
			window->close();
		else if(event.key.code == sf::Keyboard::BackSpace)
			removeChar();
		else if(hlp::findInKeyCodes(event.key.code) != -1) {
			insertChar(event.key.code);
		}
	}
}
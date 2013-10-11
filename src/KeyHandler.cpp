#include "helper.h"
#include "KeyHandler.h"

int calc_pos(int num, std::vector<int>* arr) {
	int pos = 0;
	for (int i = 0; i < num; ++i)
	{
		// If it is NOT a vowel and the previous character was a consonant
		if(!((arr->at(i) < hlp::FIRST_CONS) && (i-1 > 0) && (arr->at(i-1) > hlp::FIRST_CONS))) {
			pos++;
		}
	}
	return pos;
}


// Class KeyHandler
KeyHandler::KeyHandler(sf::Window* win, std::vector<int>* charArray_p) {
	window = win;
	charArray = charArray_p;
	c_position = 0;

}
void KeyHandler::insertChar(int keyCode) {
	std::vector<int>::iterator it;
	it = charArray->begin();
	if(c_position <= charArray->size()) {
		charArray->insert(it+c_position, keyCode);
		c_position++;
	}
	// for(auto& x: *charArray)
	// 	std::cout << ' ' << x;
	// std::cout << '\n';
}
void KeyHandler::removeChar() {
	std::vector<int>::iterator it;
	it = charArray->begin();
	if(c_position > 0) {
		c_position--;
		charArray->erase(it + c_position);
	}
}
void KeyHandler::moveCursor(char dir) {
	switch (dir) {
	case 'l':
		if(c_position >= 20)
			c_position -= 20;
		break;
	case 'r':
		if(c_position + 20 <= charArray->size())
			c_position += 20;
		break;
	case 'u':
		if(c_position > 0)
			c_position -= 1;
		break;
	case 'd':
		if (c_position < charArray->size())
			c_position ++;
		break;
	default:
		std::cout << "Not a valid direction\n";
	}
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
		else if(event.key.code == sf::Keyboard::Left)
			moveCursor('l');
		else if(event.key.code == sf::Keyboard::Right)
			moveCursor('r');
		else if(event.key.code == sf::Keyboard::Up)
			moveCursor('u');
		else if(event.key.code == sf::Keyboard::Down)
			moveCursor('d');
		else if(hlp::findInKeyCodes(event.key.code) != -1) {
			insertChar(event.key.code);
		}
	}
}
void KeyHandler::drawCursor(sf::RenderWindow* win) {
	int display_position = calc_pos(c_position, charArray);
	sf::RectangleShape rectangle(sf::Vector2f(30, 1));
	int col = display_position / 20;
	int row = display_position % 20;
	rectangle.setPosition(col * 20, row * 20);
	win->draw(rectangle);
}
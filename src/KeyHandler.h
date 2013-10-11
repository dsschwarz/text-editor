#ifndef KH_H
#define KH_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
class KeyHandler {
public:
	KeyHandler(sf::Window* win, std::vector<int>* charArray_p);

	void insertChar(int keyCode);
	void removeChar();
	void handleEvents(sf::Event event);
	void drawCursor(sf::RenderWindow* win);
	void moveCursor(char dir);
	sf::Window* window;
	std::vector<int>* charArray;

private:
	//cursor position
	int c_position;
};
#endif
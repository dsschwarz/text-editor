#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

namespace hlp {
	const int KEY_CODES_SIZE = 5;
	extern int keyCodes[KEY_CODES_SIZE];
	extern sf::Texture textures[KEY_CODES_SIZE];
	std::string getFileName(int imageNum);
	void loadImages();
	int findInArray(int arr[], int len, int value);
	int findInKeyCodes(int val);
}
#endif
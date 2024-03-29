#include "helper.h"
namespace hlp {
	int keyCodes[KEY_CODES_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	sf::Texture textures[KEY_CODES_SIZE];

	std::string getFileName(int imageNum) {
		std::string filler = "";
		if(imageNum < 10) {
			filler = "0";
		}
		std::stringstream ss;
		ss << imageNum;
		return "imgs/c" + filler + ss.str() + ".png";
	}
	void loadImages(){
		for (int i = 0; i < KEY_CODES_SIZE; i++)
		{
			sf::Texture texture;
			if(!texture.loadFromFile(getFileName(keyCodes[i])))
				std::cout << "Could not load image: " + getFileName(keyCodes[i]);
			textures[i] = texture;
		}
	}
	void outputKeyMapping(){
		std::cout << "Key Mapping" << '\n';
		for (int i = 0; i < KEY_CODES_SIZE; ++i)
		{
			std::cout << i << ": " << keyCodes[i] << '\n';
		}
	}
	int findInArray(int arr[], int len, int value) {
		for (int i = 0; i < len; ++i)
		{
			if(arr[i] == value)
				return i;
		}
		return -1;
	}
	int findInKeyCodes(int val) {
		return findInArray(keyCodes, KEY_CODES_SIZE, val);
	}
}
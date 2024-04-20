#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <SFML/Graphics.hpp>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::ifstream;
using std::ios;
using sf::Texture;
using sf::Sprite;

class card
{
public:
	card(void);
	card(int value, char suit, string image);
	card(card& copy);

	int getValue(void);
	char getSuit(void);
	string getImage(void);
	Texture& getTexture(void);
	Sprite& getSprite(void); 

	void setValue(int value);
	void setSuit(char suit);
	void setImage(string image);
	void setTexture(string textureReadInFromFile);
	void setSprite(Texture &cardTexture);

	void print(void);

private:
	int value;
	char suit;
	string image;
	Sprite cardSprite;
	Texture cardTexture;

};


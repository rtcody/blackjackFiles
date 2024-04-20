#include "card.hpp"

card::card()
{
	this->value = 0;
	this->suit = '\0';
	this->image = "\0";
}

card::card(int value, char suit, string image)
{
	this->value = value;
	this->suit = suit;
	this->image = image;
	//createSprite();
}

card::card(card& copy)
{
	this->value = copy.value;
	this->suit = copy.suit;
	this->image = copy.image;
}

int card::getValue()
{
	return value;
}

char card::getSuit()
{
	return suit;
}

string card::getImage()
{
	return image;
}

Texture& card::getTexture(void)
{
	return cardTexture; 
}

Sprite& card::getSprite(void)
{
	return cardSprite; 
}

void card::setValue(int value)
{
	this->value = value;
}

void card::setSuit(char suit)
{
	this->suit = suit;
}

void card::setImage(string image)
{
	this->image = image;
}

void card::setTexture(string textureReadInFromFile)
{
	cardTexture.loadFromFile(textureReadInFromFile);
}

void card::setSprite(Texture& cardTexture)
{
	cardSprite.setTexture(cardTexture); 
}

void card::print()
{
	cout << "Value: " << value << ", Suit: " << suit << endl; 
}

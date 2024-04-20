#pragma once
#include "hand.hpp"

class Button : public sf::Sprite 
{
public:
	Button(sf::Texture& buttonTexture);


};


class HitButton : public Button
{
public: 
	HitButton(sf::Texture& buttonText) : Button(buttonText)
	{
		this->setPosition(1500, 300);
		this->setScale(8.0f, 8.0f);
	}
private:
};

class DoubleDownButton : public Button
{
public:
	DoubleDownButton(sf::Texture& DoubleDownButtonTexture) : Button(DoubleDownButtonTexture)
	{
		this->setPosition(1700, 300);
		this->setScale(8.0f, 8.0f);
	}
private: 
};

class SplitButton : public Button
{
public:
	SplitButton(sf::Texture& SplitTexture) : Button(SplitTexture)
	{
		this->setPosition(1500, 500);
		this->setScale(8.0f, 8.0f);
	}
private:
};

class StandButton : public Button
{
public:
	StandButton(sf::Texture& StandTexture) : Button(StandTexture)
	{
		this->setPosition(1700, 500);
		this->setScale(8.0f, 8.0f);
	}
private:
};

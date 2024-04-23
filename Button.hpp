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

class oneButton : public Button
{
public:
	oneButton(sf::Texture& oneTexture) : Button(oneTexture)
	{
		this->setPosition(50, 15); 
		this->setScale(4.0f, 4.0f); 
	}
}; 

class fiveButton : public Button
{
public:
	fiveButton(sf::Texture& fiveTexture) : Button(fiveTexture)
	{
		this->setPosition(30, 100); 
		this->setScale(5.0f, 5.0f);  
	}
};

class twentyFiveButton : public Button
{
public:
	twentyFiveButton(sf::Texture& twentyFiveTexture) : Button(twentyFiveTexture)
	{
		this->setPosition(50, 250);
		this->setScale(4.0f, 4.0f); 
	}
};

class oneHundredButton : public Button
{
public:
	oneHundredButton(sf::Texture& oneHundredTexture) : Button(oneHundredTexture)
	{
		this->setPosition(50, 350); 
		this->setScale(4.0f, 4.0f); 
	}
};

class doneButton : public Button
{
public:
	doneButton(sf::Texture& doneTexture) : Button(doneTexture)
	{
		this->setPosition(175, 30); 
		this->setScale(2.75f, 2.75f); 
	}
};

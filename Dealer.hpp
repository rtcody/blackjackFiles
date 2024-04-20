#pragma once

#include "hand.hpp"

//Ben working on display for player

class Dealer : public Hand
{
public:
	Dealer(Deck& gDeck) : Hand(gDeck) //initialized the players hands from the deck
	{

	}
	void displayHand(sf::RenderWindow& window, int x, int y); 


};


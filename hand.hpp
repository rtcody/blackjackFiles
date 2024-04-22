#pragma once

#include "deck.hpp" 

//Joey working on hand 
class Hand
{

public:
	/// <summary>
	/// Hand constructor that takes in game deck 
	/// </summary>
	/// <param name="gameDeck"></param>
	Hand(Deck& gameDeck);
	//virtual void displayHand() = 0; // will have a different display hand in both the player and dealer class
	/// <summary>
	/// computes the numerical value of the entire hand
	/// </summary>
	/// <returns>the total value of the hand</returns>
	void computeHandValue();
	int computeHandValue(card dummyHand[11]);
	/// <summary>
	/// adds a card to the blackjackHand
	/// 
	/// </summary>
	/// <param name="gameDeck"></param>
	void hit(Deck& gameDeck);

	/// <summary>
	/// virtual display hand (different for both player and dealer 
	/// </summary>
	virtual void displayHand(sf::RenderWindow& window, int x, int y, bool didDoubleD) = 0;

	card getCard(int index);
	int getHandValue();


protected: //changed to protected by Ben
	card blackjackHand[11]; // 11 is the most cards you can have (All Aces) 
	int cardCount; // used to ensure we do not go out of bounds in the array; 
	int handValue; // total value of the hand 

};

#include "hand.hpp"

//Joey working on hand

/// <summary>
	/// Hand constructor that takes in game deck 
	/// </summary>
	/// <param name="gameDeck"></param>
Hand::Hand(Deck& gameDeck)
{
	handValue = 0;
	gameDeck.shuffle();
	blackjackHand[0] = gameDeck.getCard(0);
	gameDeck.shuffle();
	blackjackHand[1] = gameDeck.getCard(0); // since we shuffled it can be pulled from the top of the deck 

	cardCount = 2;
	computeHandValue();
}

/// <summary>
	/// computes the numerical value of the entire hand
	/// </summary>
	/// <returns>the total value of the hand</returns> not anymore
void Hand::computeHandValue()

{
	int numAces = 0;
	handValue = 0;
	for (int i = 0; i < cardCount; i++)
	{
		if (blackjackHand[i].getValue() != 1)
		{
			handValue += blackjackHand[i].getValue(); // computes the hand value if the card isnt an ace
		}
		else
		{
			numAces++; //tracks aces
		}

	}

	for (int i = 0; i < numAces; i++)
	{
		if ((handValue + 11) <= 21) //if ace being 11 wont have the hand bust, 11 is added to the value 
		{
			handValue += 11;
		}
		else
		{
			handValue += 1; //else one is added to the value 
		}
	}
}


int Hand::computeHandValue(card dummyHand[11])
{
	int newHandValue = 0, numAces = 0;


	for (int i = 0; i < cardCount; i++)
	{
		if (dummyHand[i].getValue() != 1)
		{
			newHandValue += dummyHand[i].getValue(); // computes the hand value if the card isnt an ace   
		}
		else
		{
			numAces++; //tracks aces 
		}

	}


	for (int i = 0; i < numAces; i++)
	{
		if (newHandValue + 11 <= 21) //if ace being 11 wont have the hand bust, 11 is added to the value 
		{
			newHandValue += 11;
		}
		else
		{
			newHandValue += 1; //else one is added to the value
		}
	}

	return newHandValue;
}

/// <summary>
	/// adds a card to the blackjackHand
	/// </summary>
	/// <param name="gameDeck"></param>
void Hand::hit(Deck& gameDeck)
{
	int i = 0;

	for (; i < cardCount; i++)
	{
		// gets to one slot above the current card count 
	}

	cardCount = i + 1; //total cards added is updated 

	gameDeck.shuffle();  // reshuffle deck 

	blackjackHand[i] = gameDeck.getCard(0);  //adds the card to the hand

}

card Hand::getCard(int index)
{

	return blackjackHand[index];

}

int Hand::getHandValue()
{
	computeHandValue();
	return handValue;

}

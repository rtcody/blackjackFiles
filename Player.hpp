#include "hand.hpp"

//Ben working on display for player

class Player : public Hand
{
public:
	Player(Deck& gDeck) : Hand(gDeck) //initialized the players hands from the deck
	{

	}


	void displayHand(sf::RenderWindow& window, int x, int y);

	/// <summary>
	/// dictates weather the player can split their hand or not
	/// </summary>
	/// <returns></returns>
	bool canSplit();

	bool DoubleDown(Deck& gameDeck);


};

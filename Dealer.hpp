#include "hand.hpp"

class Dealer : public Hand
{
public:
	Dealer(Deck& gameDeck); 
	void displayHand();

private:

	int xCordForNextCard; 
	int yCordForNextCard; 
};

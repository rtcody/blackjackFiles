#pragma once
#include "card.hpp"

#define deckSize 52

class Deck
{
public:
	Deck();
	~Deck();

	card* getCards(void);

	card getCard(int index);

	void shuffle(void);

private:
	card cards[deckSize];

};

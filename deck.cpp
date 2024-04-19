
#include "deck.hpp"

Deck::Deck()
{
	card temp;
	ifstream file;
	file.open("deck.csv", ios::in);
	string trash;
	getline(file, trash);

	for (int i = 0; i < 52; i++)
	{
		getline(file, trash, ',');
		temp.setValue(stoi(trash));

		getline(file, trash, ',');
		temp.setSuit(trash[0]);

		getline(file, trash);
		temp.setImage(trash);

		cards[i] = temp;


	}
}

Deck::~Deck()
{

}

card* Deck::getCards()
{
	return cards;
}

card Deck::getCard(int index)
{
	return cards[index];
}

void Deck::shuffle(void)
{
	int j;
	card temp;
	for (int i = deckSize - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		temp = cards[j];
		cards[j] = cards[i];
		cards[i] = temp;
	}
}

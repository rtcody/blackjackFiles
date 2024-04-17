#include "card.hpp"
#define deckSize 52

class Deck
{
public:
	Deck(); 
	~Deck();  

	card* getCards(void);      

	card getCard(int& index); 
	card getCard(int index); 

	void shuffle(void); 

private:
	card* cards;   
};

Deck::Deck()
{
	card temp; 
	cards = new card[deckSize];  
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
	}
}

Deck::~Deck()
{
	delete cards;       
}

card* Deck::getCards()
{
	return cards; 
}

card Deck::getCard(int& index)
{
	index++; 
	return cards[index - 2]; 
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

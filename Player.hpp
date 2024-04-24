#include "hand.hpp"

//Ben working on display for player

class Player : public Hand
{
public:

	Player(Deck& gDeck) : Hand(gDeck) //initialized the players hands from the deck
	{
		bankAmount = 0;
		betAmount = 0;
	}

	void displayHand(sf::RenderWindow& window, int x, int y, bool didDoubleD);

	/// <summary>
	/// dictates weather the player can split their hand or not
	/// </summary>
	/// <returns></returns>
	bool canSplit();

	bool DoubleDown(Deck& gameDeck);


	Player* split();

	bool canBet(int potBet);

	void setBet(int betAmount);

	void setBank(int bankAmount);

	int getBank();

	int getBet();

	void betPayout(void);
	void betLoser(void);
	void betBlackJack(void);

	string createWinMes(void);
	string createLossMes(void);
	string createBetAmount(void);
	string createBankAmount(void);
	string createHitMes(void);


	string playerStood = "Player stood. \n", playerDD = "Player doubled down. \n", playerDraw = "Player and Dealer drew. \n", playerSplit = "Player split \n";

private:
	int bankAmount;
	int betAmount;
};

#include "test.hpp"

//constructor and destructor
Test::Test(void)
{
	cout << "Test constructor..." << endl;
}

Test::~Test(void)
{
	cout << "Test destructor..." << endl;
}

/******************************************************************************\
*	Method name: testDeckCreation
*	Date last modified: 4/17/24
*	Description: this function will test the ability of the create deck function
*				 and if the first and last card are what they are supposed to be.
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: none
*	Postcondition: none
\******************************************************************************/
void Test::testDeckCreation()
{
	Deck testDeck;
	card firstCard, lastCard;

	ifstream file;
	file.open("deck.csv", ios::in);
	string trash;

	//create the first card
	getline(file, trash);

	getline(file, trash, ',');
	firstCard.setCardNum(stoi(trash));

	getline(file, trash, ',');
	firstCard.setValue(stoi(trash));

	getline(file, trash, ',');
	firstCard.setSuit(trash[0]);

	getline(file, trash);
	firstCard.setImage(trash);

	//skip all lines until the very last line
	for (int i = 0; i < 50; i++)
	{
		getline(file, trash);
	}

	//create the last card
	getline(file, trash, ',');
	lastCard.setCardNum(stoi(trash));

	getline(file, trash, ',');
	lastCard.setValue(stoi(trash));

	getline(file, trash, ',');
	lastCard.setSuit(trash[0]);

	getline(file, trash);
	lastCard.setImage(trash);

	//compare our first and last cards images to the decks first and last
	assert(firstCard.getImage() == testDeck.getCard(0).getImage());
	cout << "Checkpoint 1 passed." << endl;

	assert(lastCard.getImage() == testDeck.getCard(51).getImage());
	cout << "Deck creation test passed." << endl << endl;
}

/******************************************************************************\
*	Method name: testDeckShuffle();
*	Date last modified: 4/17/24
*	Description: function will compare a newly created deck to a shuffled deck
*				 and will pass the test if at least half cards are in new
				 positions
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: none
*	Postcondition: none
\******************************************************************************/
void Test::testDeckShuffle()
{
	Deck freshDeck, shuffledDeck;
	int uniquePosition = 0;

	shuffledDeck.shuffle();

	for (int i = 0; i < 52; i++)
	{
		if (shuffledDeck.getCard(i).getImage() != freshDeck.getCard(i).getImage())
		{
			uniquePosition++;
		}
	}

	assert(uniquePosition >= 26);
	cout << "Deck shuffle test passed" << endl << endl;
}

/******************************************************************************\
*	Method name: testHandPopulation
*	Date last modified: 4/17/24
*	Description: function will test that each hand is populated with 2 cards and
*				 that they are not equal to null
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: none
*	Postcondition:none
\******************************************************************************/
void Test::testHandPopulation()
{
	card compareCard;
	Deck helperDeck;
	Dealer testHand(helperDeck);

	string dummy = "\0";

	for (int i = 0; i < 9; i++)
	{
		testHand.hit(helperDeck);
	}

	for (int i = 0; i < 11; i++)
	{
		assert(testHand.getCard(i).getImage() != dummy);
		cout << "Checkpoint " << i + 1 << " passed" << endl;
	}

	cout << "Test hand population passed" << endl << endl;
}

/******************************************************************************\
*	Method name: testAcesCalculation
*	Date last modified: 4/17/24
*	Description: function will test that the correct logic is applied when trying
*				 to compute the score of a given blackjack hand
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: void
*	Postcondition: void
\******************************************************************************/
void Test::testAcesCalculation()
{
	Deck testDeck;
	Dealer testHand(testDeck);
	int value = 0, expectedValue = 17, expectedValue2 = 21;
	card dummyHand[11], dummyHand2[11];

	dummyHand[0].setValue(1);
	dummyHand[1].setValue(6);

	dummyHand2[0].setValue(1);
	dummyHand2[1].setValue(10);
	dummyHand2[2].setValue(10);

	value = testHand.computeHandValue(dummyHand);

	assert(value == expectedValue);
	cout << "Checkpoint 1 passed" << endl;

	value = testHand.computeHandValue(dummyHand2);

	assert(value == expectedValue2);
	cout << "Ace calculation test passed" << endl << endl;
}

/******************************************************************************\
*	Method name: testHtt
*	Date last modified: 4/24/2024
*	Description: function will test the hit function
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: void
*	Postcondition: void
\******************************************************************************/
void Test::testHit()
{
	Deck testDeck;
	Dealer testHand(testDeck);

	testHand.hit(testDeck);

	
	assert(testHand.getCard(2).getCardNum() != 0);
	cout << "card number checkpoint passed" << endl;

	assert(testHand.getCard(2).getValue() != 0);
	cout << "card value checkpoint passed" << endl;

	assert(testHand.getCard(2).getSuit() != '\0');
	cout << "suit checkpoint passed" << endl;

	assert(testHand.getCard(2).getImage() != "\0"); 
	cout << "image checkpoint passed" << endl << endl; 
}

	

/******************************************************************************\
*	Method name: runTests
*	Date last modified: 4/17/24
*	Description: function runs all test cases
*	Input parameters: void
*	Directly returns: void
*	Indirectly returns: void
*	Precondition: none
*	Postcondition: none
\******************************************************************************/
void Test::runTests()
{
	cout << endl << "-----Test Deck Creation-----" << endl;
	testDeckCreation();

	cout << endl << "-----Test Shuffle-----" << endl;
	testDeckShuffle();

	cout << endl << "-----Test Hand Population-----" << endl;
	testHandPopulation();

	cout << endl << "-----Test Ace Calculation -----" << endl;
	testAcesCalculation();

	cout << endl << "-----Test Hit-----" << endl;
	testHit();

	system("Pause");
	system("cls");

	cout << "---------------------------------BLACKJACK DESCRIPTION---------------------------------" << endl;
	cout << "Blackjack is a popular card game where players aim to beat the dealer's hand without going" << endl;
	cout << "over 21. Each player and the dealer start with two cards, and players can choose to 'hit' " << endl;
	cout << "for another card or 'stand' with their current hand.Going over 21 results in a loss. After " << endl;
	cout << "all players finish their turns, the dealer reveals their cards and must hit until reaching " << endl;
	cout << "a total of 17 or higher.Winning hands are those closer to 21 than the dealer's without " << endl;
	cout << "busting. Getting a 'blackjack' with an Ace and a 10 - value card earns a higher payout." << endl;
	cout << "Master the basics and enjoy the excitement of blackjack!" << endl << endl;

	system("Pause");

}

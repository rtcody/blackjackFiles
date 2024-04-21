#include "Player.hpp"


void Player::displayHand(sf::RenderWindow& window, int x, int y)
{


    for (int i = 0; i < cardCount; i++)
    {
        //get the texture for the current card
        std::string cardImage = blackjackHand[i].getImage();
        //  sf::Texture texture;
        blackjackHand[i].setTexture(cardImage);

        //create a sprite for the current card
     //   sf::Sprite cardSprite(texture);
        blackjackHand[i].setSprite(blackjackHand[i].getTexture());
        blackjackHand[i].getSprite().setScale(0.35f, 0.35f);

        //set position the card
        blackjackHand[i].getSprite().setPosition(x, y);

        //draw the card to the window
        window.draw(blackjackHand[i].getSprite());

        x += 100; //reposition x coordinate for the next card
        y -= 100; //reposition y coordinate for the next card
    }
}

/// <summary>
    /// dictates weather the player can split their hand or not
    /// </summary>
    /// <returns></returns>
bool Player::canSplit()
{
    bool split = false;

    if (blackjackHand[0].getCardNum() == blackjackHand[1].getCardNum()) // if the first two cards are same number 
    {
        split = true;
    }

    return split;

}

bool Player::DoubleDown(Deck& gameDeck)
{
    int i = 0;

    for (; i < cardCount; i++)
    {
        // gets to one slot above the current card count 
    }

    cardCount = i + 1; //total cards added is updated 

    gameDeck.shuffle();  // reshuffle deck 

    blackjackHand[i] = gameDeck.getCard(0);  //adds the card to the hand

    return false; // will always return false 
}

bool Player::canBet()
{
    return betAmount <= bankAmount;
}

void Player::setBet(int betAmount)
{
    this->betAmount = betAmount;
}

void Player::setBank(int bankAmount)
{
    this->bankAmount = bankAmount;
}

int Player::getBank()
{
    return bankAmount;
}

int Player::getBet()
{
    return betAmount;
}

void Player::betPayout()
{
    bankAmount += betAmount;
}

void Player::betLoser()
{
    bankAmount -= betAmount;
}

void Player::betBlackJack()
{
    betAmount = betAmount * 2;
    betPayout();
}

Player* Player::split()
{
    //
    //
    //TRUTH LOGIC NOT PLACED YET FOR EASIER TESTING
    //
    //

    Deck myD;
    Player player1(myD), player2(myD);

    //set the first card for each new hand equal to the similar card of the original hand
    player1.getCard(0).setValue(blackjackHand[0].getValue());
    player1.getCard(0).setSuit(blackjackHand[0].getSuit());
    player1.getCard(0).setImage(blackjackHand[0].getImage());

    player2.getCard(0).setValue(blackjackHand[0].getValue());
    player2.getCard(0).setSuit(blackjackHand[0].getSuit());
    player2.getCard(0).setImage(blackjackHand[0].getImage());

    //make player array with both hands, why was this so hard lol 
    Player twoHands[2] = { player1, player2 };

    return twoHands;
}

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

    if (blackjackHand[0].getValue() == blackjackHand[1].getValue()) // if the first two cards are same number 
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

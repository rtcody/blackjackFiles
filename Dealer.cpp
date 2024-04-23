#include "Dealer.hpp"


void Dealer::displayHand(sf::RenderWindow& window, int x, int y, bool didDoubleD)  // didDoubleD does nothing here but needed for polymorphism

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

        x -= 200; //reposition x coordinate for the next card
    }
}

void Dealer::dealerAI(Deck& gDeck)
{
    while (getHandValue() < 17)
    {
        int i = 0;
        for (; i < cardCount; i++)
        {

        }
        cardCount = i + 1;
        gDeck.shuffle();
        blackjackHand[i] = gDeck.getCard(0);
    }


}

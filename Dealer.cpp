#include "Dealer.hpp"

void Dealer::displayHand(sf::RenderWindow& window) 

{
    float x = 950; //starting x coordinate
    float y = 50; //starting y coordate

    for (int i = 0; i < cardCount; i++)
    {
        //get the texture for the current card
        std::string cardImage = blackjackHand[i].getImage();
        sf::Texture texture;
        texture.loadFromFile(cardImage);

        //create a sprite for the current card
        sf::Sprite cardSprite(texture);
        cardSprite.setScale(0.35f, 0.35f);

        //set position the card
        cardSprite.setPosition(x, y);

        //draw the card to the window
        window.draw(cardSprite);

        x -= 200; //reposition x coordinate for the next card
    }
}

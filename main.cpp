#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "hand.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "test.hpp"
#include "Button.hpp"
#include "Client.h"

using sf::Texture;
using sf::Sprite;

int main(void)
{
    //WSADATA wsaData;
    //SOCKET clientSocket;
    //sockaddr_in serverAddr;

    //initCreateConnect(wsaData, clientSocket, serverAddr);

    //string message;

    //// Prompt user for input
    //message = promptForInput();

    //// Send user input to server
    //sendToServer(message, clientSocket);

    //// Close socket
    //closeSocket(clientSocket);

    srand((unsigned int)time(NULL));

     Test t;
     t.runTests();

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "BLACKJACK"); 
     
    Texture b;
    b.loadFromFile("Cards/background.png");

    Sprite background(b);
    background.setScale(1.5f, 1.5f);

    Texture x1;
    x1.loadFromFile("Cards/card back black.png");

    //this is a set position for the backcard and I think we should keep it in main in the future because we can control when we want to remove it
    Sprite backCard(x1);
    backCard.setScale(0.26f, 0.26f);
    backCard.setPosition(950, 50);

    Deck gDeck;
    Player player(gDeck);
    Dealer dealer(gDeck); 

    Texture HitTexture;
    HitTexture.loadFromFile("Cards/redHitButton.png");
    HitButton Hit(HitTexture);

    bool playerHit = false;

 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) //check for mouse button press
            {
                if (event.mouseButton.button == sf::Mouse::Left) //check left mouse button is pressed
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); 
                    if (Hit.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && player.getCard(10).getImage() == "\0") //if mouse is clicked the hit buttton
                    {
                        playerHit = true;
                        player.hit(gDeck);  
                    }
                }
            }

        }

        if (player.canSplit())
        {
            //button for if the player chose to split


        }



        window.clear();
        window.draw(background);
        window.draw(Hit); 
        dealer.displayHand(window); 
        window.draw(backCard); 
        player.displayHand(window); 
        window.display();
   
    }
    return 0;
}


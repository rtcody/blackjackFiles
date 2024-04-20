#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "hand.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "test.hpp"
#include "Button.hpp"

//Joey - I dont have client or any server thing so I will just be commenting the server stuff out 
//#include "Client.h"


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

    //hit button creation 
    Texture HitTexture;
    HitTexture.loadFromFile("Cards/redHitButton.png");
    HitButton Hit(HitTexture);

    //double down button creation 
    Texture DDtexture;
    DDtexture.loadFromFile("Cards/greenDoubleDown.png"); 
    DoubleDownButton DoubleDown(DDtexture); 

    //stand button creation 
    Texture standTexture; 
    standTexture.loadFromFile("Cards/StandButton.png");
    StandButton Stand(standTexture);  

    //split button creation
    Texture splitTexture; 
    splitTexture.loadFromFile("Cards/greySplitButton.png");
    SplitButton Split(splitTexture); 

    Sprite card3forDD; 

    bool canHit = true;
    bool isAbleToSplit = false; // bool to identify if player is able to split 
    bool didDoubleDown = false; 


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

                    if (Hit.getGlobalBounds().contains(mousePosition.x, mousePosition.y)    //if mouse is clicked the hit buttton
                        && player.getHandValue() < 21 // and value is less than 21 (player can hit)
                        && canHit == true)   // player did not double down 
                    {
                 
                        player.hit(gDeck);
                    }

                    if (player.getHandValue() >= 21) // if cannot hit anymore 
                    {
                        HitTexture.loadFromFile("Cards/greyHitButton.png");
                        Hit.setTexture(HitTexture);
                    }

                    if (DoubleDown.getGlobalBounds().contains(mousePosition.x, mousePosition.y) // if on first two cards can double down 
                        && player.getCard(2).getImage() == "\0")
                    {
                        canHit = player.DoubleDown(gDeck);   // can hit set to false 
                        player.getCard(2);
                        didDoubleDown = true; // will be used to rotate card because after a double down you cant hit 

                    }

                  

                  
                }

                if (player.getCard(2).getImage() != "\0") // if player cannot double down anymore change sprite immage 
                {
                    DDtexture.loadFromFile("Cards/greyDoubleDown.png");
                    DoubleDown.setTexture(DDtexture);

                }
            }

            if (player.canSplit() && player.getCard(2).getImage() == "\0")   // if first two cards have the same value (can split)
            {
                splitTexture.loadFromFile("Cards/splitButton.png");
                Split.setTexture(splitTexture);
            }
            else // cannot split 
            {
                splitTexture.loadFromFile("Cards/greySplitButton.png");
                Split.setTexture(splitTexture);
            }

            if (player.getHandValue() >= 21 || canHit == false) // cannot hit anymore 
            {
                HitTexture.loadFromFile("Cards/greyHitButton.png");
                Hit.setTexture(HitTexture);
            }

            if (didDoubleDown == true)
            {
                player.getCard(2).getSprite().setRotation(90); 
            }
            
        }

       
        window.clear();
        window.draw(background);
        //buttons drawn
        window.draw(Hit);
        window.draw(DoubleDown); 
        window.draw(Stand); 
        window.draw(Split); 

        dealer.displayHand(window, 950,50); 
        window.draw(backCard);
        player.displayHand(window,820,800);
        window.display();

    }
    return 0;
}

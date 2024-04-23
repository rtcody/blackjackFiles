#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "hand.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include "test.hpp"
#include "Button.hpp"
#include "windows.h"


//Joey - I dont have client or any server thing so I will just be commenting the server stuff out 
//#include "Client.h"


int main(void)
{
    
    //WSADATA wsaData;
    //SOCKET clientSocket;
    //sockaddr_in serverAddr;

    //initializeSocket(wsaData);  
    //createSocket(clientSocket); 
    //connectToServer(serverAddr, clientSocket); 

    //string message = player.createBankAmount(); 

    //// Send user input to server
    //sendToServer(message, clientSocket);

    //// Close socket
    //closeSocket(clientSocket);



    ////  Test t;
    ////t.runTests(); 

    srand((unsigned int)time(NULL));
    Deck gDeck; 
    Player player(gDeck);  
    Dealer dealer(gDeck); 
    player.setBank(200);  

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

    //outcome sprite (win/loss/tie)
    Texture outcomeTexture;
    outcomeTexture.loadFromFile("Cards/loser.png");
    Sprite outcome(outcomeTexture);

    //one dollar bet button
    Texture oneDollarText;
    oneDollarText.loadFromFile("Cards/oneDollar.png");
    oneButton oneDollar(oneDollarText);     

    //five dollar bet button 
    Texture fiveDollarText; 
    fiveDollarText.loadFromFile("Cards/fiveDollar.png"); 
    fiveButton fiveDollar(fiveDollarText);    

    //twenty five bet button
    Texture twentyFiveText; 
    twentyFiveText.loadFromFile("Cards/twentyFiveDollar.png"); 
    twentyFiveButton twentyFiveDollar(twentyFiveText); 

    //one hundred bet button
    Texture oneHundText; 
    oneHundText.loadFromFile("Cards/oneHundredDollar.png"); 
    oneHundredButton oneHundredDollar(oneHundText); 

    //done betting button 
    Texture doneText; 
    doneText.loadFromFile("Cards/doneBetting.png"); 
    doneButton done(doneText);  

    bool betting = true; 
    bool canHit = true;
    bool isAbleToSplit = false; // bool to identify if player is able to split 
    bool didDoubleDown = false;
    bool flip = false; // for the back card  
    bool didPlayerWin = false;
    bool dealerAICalled = false;
    bool outcomeDecided = false; 

    while (window.isOpen())
    {
        window.display(); 
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

                    if (oneDollar.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == true)
                    {
                        if (player.canBet(player.getBet()+1))
                        {
                            player.setBet(player.getBet() + 1);
                        }
                    }

                    if (fiveDollar.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == true)
                    {
                        if (player.canBet(player.getBet() + 5))
                        {
                            player.setBet(player.getBet() + 5);
                        }
                    }

                    if (twentyFiveDollar.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == true)
                    {
                        if (player.canBet(player.getBet() + 25))
                        {
                            player.setBet(player.getBet() + 25);
                        }
                    }

                    if (oneHundredDollar.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == true)
                    {
                        if (player.canBet(player.getBet() + 100))
                        {
                            player.setBet(player.getBet() + 100);
                        }
                    }

                    if (done.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == true)    
                    {
                        betting = false;   
                        cout << player.createBetAmount(); 
                    }

                    if (Hit.getGlobalBounds().contains(mousePosition.x, mousePosition.y)    //if mouse is clicked the hit buttton
                        && player.getHandValue() < 21 // and value is less than 21 (player can hit)
                        && canHit == true
                        && betting == false)   // player did not double down 
                    {

                        player.hit(gDeck);


                    }

                    if (DoubleDown.getGlobalBounds().contains(mousePosition.x, mousePosition.y) // if on first two cards can double down 
                        && player.getCard(2).getImage() == "\0"
                        && betting == false)
                    {
                        canHit = player.DoubleDown(gDeck);   // can hit set to false 
                        player.getCard(2).getSprite().rotate(90.f);
                        didDoubleDown = true; // will be used to rotate card because after a double down you cant hit 
                        flip = true;
                    }

                    if (Split.getGlobalBounds().contains(mousePosition.x, mousePosition.y)
                        && betting == false)
                    {
                        if (player.canSplit() && player.getCard(2).getImage() == "\0")
                        {

                        }
                    }

                    if (Stand.getGlobalBounds().contains(mousePosition.x, mousePosition.y) && betting == false)  
                    {
                        flip = true;
                        canHit = false;
                    }
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


            if (player.getHandValue() >= 21) // cannot hit anymore 
            {
                canHit = false;
                HitTexture.loadFromFile("Cards/greyHitButton.png");
                Hit.setTexture(HitTexture);
                flip = true;
            }

            if (player.getCard(2).getImage() != "\0" || canHit == false) // if player cannot double down anymore change sprite immage 
            {
                DDtexture.loadFromFile("Cards/greyDoubleDown.png");
                DoubleDown.setTexture(DDtexture);


            }
        }


        window.clear();
        window.draw(background);
        //buttons drawn
        window.draw(Hit);
        window.draw(DoubleDown);
        window.draw(Stand);
        window.draw(Split);
        window.draw(oneDollar); 
        window.draw(fiveDollar);   
        window.draw(twentyFiveDollar);  
        window.draw(oneHundredDollar); 
        window.draw(done); 




        dealer.displayHand(window, 950, 50, didDoubleDown);
        if (flip == false)
        {
            window.draw(backCard);

        }

        player.displayHand(window, 820, 800, didDoubleDown);
        didDoubleDown = false;


        if (canHit == false || didDoubleDown == true) // player cannot do anything anymore so now for calculations
        {
            if (dealerAICalled == false)
            {
                dealer.dealerAI(gDeck);
                dealerAICalled = true;
            }

            else
            {
                standTexture.loadFromFile("Cards/greyStandButton.png");
                Stand.setTexture(standTexture);

                //winner and loser logic 
                if ((player.getHandValue() > dealer.getHandValue()) && (21 > dealer.getHandValue()) && (player.getHandValue() <= 21) && outcomeDecided == false)  // player won 
                {
                    outcomeTexture.loadFromFile("Cards/win.png");
                    player.betPayout(); 
                    cout << player.createWinMes(); 
                    outcomeDecided = true; 
                }
                else if ((21 < dealer.getHandValue()) && (player.getHandValue() <= 21) && outcomeDecided == false) // dealer busted 
                {
                    outcomeTexture.loadFromFile("Cards/dealerBust.png");
                    player.betPayout();
                    cout << player.createWinMes(); 
                    outcomeDecided = true;
                }
                else if ((player.getHandValue() > dealer.getHandValue()) && (21 < player.getHandValue()) && (dealer.getHandValue() <= 21) && outcomeDecided == false) // player bust  
                {
                    player.betLoser(); 
                    cout << player.createLossMes(); 
                    outcomeDecided = true;
                    outcomeTexture.loadFromFile("Cards/bust.png");
  
                }
                else if (((player.getHandValue() < dealer.getHandValue()) && (21 > player.getHandValue())) && (dealer.getHandValue() <= 21) && outcomeDecided == false) // dealer wins
                {
                    player.betLoser();   
                    cout << player.createLossMes(); 
                    outcomeDecided = true; 
                    outcomeTexture.loadFromFile("Cards/loser.png");
                }
                else if (player.getHandValue() == 21 && (player.getHandValue() > dealer.getHandValue() || dealer.getHandValue() < 21) && outcomeDecided == false) //blackjack wins
                {
                    outcomeTexture.loadFromFile("Cards/win.png");  
                    player.betBlackJack();  
                    cout << player.createWinMes();   
                    outcomeDecided = true;
                }
                else if(player.getHandValue() == dealer.getHandValue() && player.getHandValue() <= 21 && outcomeDecided == false)
                {
                    outcomeTexture.loadFromFile("Cards/push.png");
                    cout << player.playerDraw;   
                    outcomeDecided = true;
                }

                outcome.setTexture(outcomeTexture);
                outcome.setScale(8.0f, 8.0f);
                outcome.setPosition(1360, 740);
                window.draw(outcome);
            }
        }

        window.display();
    }
    return 0;
}

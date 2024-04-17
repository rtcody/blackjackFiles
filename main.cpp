#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using sf::Texture;
using sf::Sprite;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "BLACKJACK");

    Texture b;
    b.loadFromFile("Cards/background.png");

    Sprite background(b);
    background.setScale(1.5f, 1.5f);

    Texture x1;
    x1.loadFromFile("Cards/jack_of_hearts2.png");
    Texture x2;
    x2.loadFromFile("Cards/ace_of_diamonds.png");

    Sprite card1(x1);
    card1.setScale(0.35f, 0.35f);
    card1.setPosition(820, 800);

    Sprite card2(x2);
    card2.setScale(0.35f, 0.35f);
    card2.setPosition(920,700);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        window.draw(background);
        window.draw(card1);
        window.draw(card2);
        window.display();
    }

    return 0;
}

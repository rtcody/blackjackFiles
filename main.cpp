#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using sf::Texture; 
using sf::Sprite; 


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
    Texture queenOHearts; 
    queenOHearts.loadFromFile("Cards/queen_of_hearts2.png"); 
    Sprite hearts(queenOHearts);   
    shape.setFillColor(sf::Color::Green);   

    Texture b;
    b.loadFromFile("background.png");

    Sprite background(b); 
    background.setScale(1.5f, 1.5f);

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
        window.draw(hearts);
        window.display();
    }

    return 0;
}

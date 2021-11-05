#include <SFML/Graphics.hpp>
#include <map>
#include "Tilemap.h"

using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;



int main()
{
    RenderWindow window(sf::VideoMode(550, 380), "SFML works!");
    Tilemap T;
    Texture maptexture;
    maptexture.loadFromFile("foresttiles2-t.png");
    T.loadLevel(maptexture);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        T.draw(window);
        
        window.display();
    }

    return 0;
}
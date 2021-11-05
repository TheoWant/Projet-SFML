#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;

#include "Tilemap.h"

int main()
{
    Tilemap T;
    Texture maptexture;
    maptexture.loadFromFile("foresttiles2-t.png");
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(T.loadLevel(maptexture));
        window.display();
    }

    return 0;
}
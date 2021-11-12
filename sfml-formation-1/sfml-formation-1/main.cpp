#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "Tilemap.h"
#include "enemy.h"
#include "player.h"

using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;



int main()
{
    RenderWindow window(sf::VideoMode(550, 380), "SFML works!");
    Tilemap T;
    Texture maptexture, enemyTexture, playerTexture;
    Player player;

    Enemy ghost;

    Vector2i anim(48, 0);

    playerTexture.loadFromFile("characters.png");
    maptexture.loadFromFile("foresttiles2-t.png");

    T.loadLevel(maptexture);
    player.loadPlayer(playerTexture);
    ghost.loadEnemy(enemyTexture);
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player.movePlayer();
        ghost.moveEnemy();
        window.clear();
        T.draw(window);
        window.draw(ghost.getSprite());
        window.draw(player.getSprite());
        player.Life(window);
        window.display();
        
    }

    return 0;
}
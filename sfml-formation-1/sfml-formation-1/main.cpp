#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "Tilemap.h"
#include "enemy.h"
#include "player.h"
#include "weapon.h"

using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;



int main()
{
    RenderWindow window(sf::VideoMode(550, 380), "SFML works!");
    
    Tilemap T;
    Texture maptexture, enemyTexture, playerTexture, weaponTexture;

    enemyTexture.loadFromFile("characters.png");
    maptexture.loadFromFile("foresttiles2-t.png");
    playerTexture.loadFromFile("characters.png");
    weaponTexture.loadFromFile("sword_normal.png");
    
    Player player;

    Enemy ghost;
    Weapon sword;

    T.loadLevel(maptexture);
    player.loadPlayer(playerTexture);
    ghost.loadEnemy(enemyTexture);
    sword.loadWeapon(weaponTexture);

    View playerView(Vector2f(0.0f, 0.0f), Vector2f(200.0f, 200.0f));

    Clock timer;

    float time = timer.getElapsedTime().asSeconds();
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        player.movePlayer();
        playerView.setCenter(player.getPlayerPosition());

        ghost.moveEnemy();

        window.clear();
        T.draw(window);
        player.drawPlayer(window);
        player.pickUp(sword);
        player.Life(window);
        ghost.draw(window);
        sword.drawWeapon(window);

        window.display();
        
    }

    return 0;
}
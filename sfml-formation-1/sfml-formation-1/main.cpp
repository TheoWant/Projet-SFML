#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include "Tilemap.h"
#include "enemy.h"
#include "player.h"
#include "weapon.h"
#include "vehicle.h"

using namespace std;
using namespace sf;
typedef Vector2f vec2;
typedef Vector2i vec2i;


int main()
{
    RenderWindow window(sf::VideoMode(550, 380), "SFML works!");
    
    Tilemap T; 
    Player player;
    Texture maptexture, enemyTexture, playerTexture, weaponTexture;

    enemyTexture.loadFromFile("characters.png");
    maptexture.loadFromFile("foresttiles2-t.png");
    playerTexture.loadFromFile("characters.png");
    weaponTexture.loadFromFile("sword_normal.png");

    Enemy ghost;
    Weapon sword;
    Vehicle horse;

    T.loadLevel(maptexture);
    player.loadPlayer(playerTexture);
    ghost.loadEnemy(enemyTexture);
    sword.loadWeapon(weaponTexture);

    View playerView(Vector2f(0.0f, 0.0f), Vector2f(200.0f, 200.0f));

    Clock timer;

    float time = timer.getElapsedTime().asSeconds();
   
    bool recupere = false;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        int playerPosX = player.getPlayerPosition().x;
        int playerPosY = player.getPlayerPosition().y;
        
        player.movePlayer();
        playerView.setCenter(player.getPlayerPosition());
        int distance_x = sqrt((player.getPlayerPosition().x - sword.getWeaponPosition().x) * (player.getPlayerPosition().x - sword.getWeaponPosition().x) + (player.getPlayerPosition().y - sword.getWeaponPosition().y) * (player.getPlayerPosition().y - player.getPlayerPosition().y));
        int distance_y = sqrt((player.getPlayerPosition().y - sword.getWeaponPosition().y) * (player.getPlayerPosition().y - sword.getWeaponPosition().y) + (player.getPlayerPosition().x - sword.getWeaponPosition().x) * (player.getPlayerPosition().x - player.getPlayerPosition().x));
        ghost.moveEnemy();

        window.clear();

        if (distance_x < 20 && distance_y < 30) {
            sword.pickUp();
            recupere = true;
        }
        T.draw(window);
        ghost.draw(window);
        int LastPosY = player.lastPosY;
        sword.Animate(window, weaponTexture, playerPosX, playerPosY, LastPosY);
        player.drawPlayer(window);
        player.Life(window);
        player.pickUp(sword);
        if (recupere == false){sword.drawWeapon(window);}
        
        window.display();
        window.clear();
    }

    return 0;
}
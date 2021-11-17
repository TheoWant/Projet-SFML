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
    bool ghostAlive = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        bool attack = false;
        int playerPosX = player.getPlayerPosition().x;
        int playerPosY = player.getPlayerPosition().y;
        int LastPosY = player.getLastPosY();
        sf::FloatRect ghostBox = ghost.getEnemyBounds();
        sf::FloatRect playerBox = player.getPlayerBounds();
        sf::FloatRect swordBox = sword.getSwordBounds();
        player.movePlayer();
        playerView.setCenter(player.getPlayerPosition());
        
        window.clear();

        
        T.draw(window);
        
        sword.Animate(window, weaponTexture, player, LastPosY);
        player.drawPlayer(window);
        player.Life(window);
        player.pickUp(sword);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            attack = true;
        }
        if (player.hasWeapon == false)
        {
            sword.drawWeapon(window);
        }
        if (playerBox.intersects(swordBox)) {
            player.hasWeapon = true;
        }

        if (attack == true) {
            if (swordBox.intersects(ghostBox)) {
                ghostAlive = false;
            }
        }
        if (ghostAlive == true) {
            ghost.draw(window);
            ghost.moveEnemy();
        }
        
        window.display();
        window.clear();
    }

    return 0;
}
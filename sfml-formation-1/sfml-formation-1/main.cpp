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
    Texture maptexture, enemyTexture, playerTexture, weaponTexture, vehicleTexture;

    enemyTexture.loadFromFile("characters.png");
    maptexture.loadFromFile("foresttiles2-t.png");
    playerTexture.loadFromFile("characters.png");
    weaponTexture.loadFromFile("sword_normal.png");
    vehicleTexture.loadFromFile("horse.png");

    Enemy ghost;
    Weapon sword;
    Vehicle horse;

    T.loadLevel(maptexture);
    player.loadPlayer(playerTexture);
    ghost.loadEnemy(enemyTexture);
    sword.loadWeapon(weaponTexture);
    horse.loadVehicle(vehicleTexture);

    View playerView(Vector2f(0.0f, 0.0f), Vector2f(200.0f, 200.0f));

    Clock timer;

    float time = timer.getElapsedTime().asSeconds();
    bool ghostAlive = true;
    bool playerOnHorse = false;
    float playerHP = 100;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float NewX = player.getPlayerPosition().x;
        float NewY = player.getPlayerPosition().y; 
        bool attack = false;
        int LastPosY = player.getLastPosY();
        sf::FloatRect ghostBox = ghost.getEnemyBounds();
        sf::FloatRect playerBox = player.getPlayerBounds();
        sf::FloatRect swordBox = sword.getSwordBounds();
        player.movePlayer();
        playerView.setCenter(player.getPlayerPosition());
        
        window.clear();
        T.draw(window);
        if (horse.horseBounds().intersects(playerBox)) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                playerOnHorse = true;
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            playerOnHorse = false;
            player.hasWeapon = false;
            horse.setTextureBack(vehicleTexture);
        }
        sword.Animate(window, weaponTexture, player, LastPosY, playerOnHorse);
        if (playerOnHorse == false && playerHP > 0) {
            player.drawPlayer(window);
            player.Life(window, playerHP);
            player.pickUp(sword);
        }
        horse.horseAnimate(playerOnHorse, LastPosY);

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
        if (ghostAlive == true) {
            if (playerBox.intersects(ghostBox)) {
                if (LastPosY == 0) {
                    NewY -= 40;
                    playerHP -= 20;
                }
                if (LastPosY == 48) {
                    NewY += 40;
                    playerHP -= 20;
                }
                if (LastPosY == 32) {
                    NewX -= 40;
                    playerHP -= 20;
                }
                if (LastPosY == 16) {
                    NewX += 40;
                    playerHP -= 20;
               }
               player.setPlayerPosition(NewX, NewY);
            }
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
        horse.drawHorse(window);
        window.display();
        window.clear();
    }

    return 0;
}
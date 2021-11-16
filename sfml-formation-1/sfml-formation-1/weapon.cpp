#include <SFML/Graphics.hpp>
#include "weapon.h"
#include "player.h"
#include <iostream>

using namespace sf; 

Player p;

bool hasWeapon = false;

void Weapon::drawWeapon(RenderWindow& window)
{
    window.draw(_weaponSprite);
}

void Weapon::loadWeapon(Texture& weaponTexture)
{
    weaponTexture.loadFromFile("sword_normal.png");
    _weaponSprite.setTexture(weaponTexture);
    _weaponSprite.scale(1, 1);
    _weaponSprite.setPosition(200, 300);
}

void Weapon::pickUp() {
    hasWeapon = true;
}

sf::Vector2f Weapon::getWeaponPosition()
{
    return _weaponSprite.getPosition();
}
bool Weapon::attack()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        
    }
}


void Weapon::Animate(RenderWindow& window, Texture& weaponTexture, int playerPosX, int playerPosY, int LastPosY) 
{
    float deltaTime = timer.restart().asSeconds();

    attackTimer += deltaTime;

    _weaponSprite.setOrigin(0, 0);

    if (hasWeapon == true) {
        if (LastPosY == 0) {
            _weaponSprite.setPosition(playerPosX + 22, playerPosY + 12);
            angleStart = 340;
            _weaponSprite.setRotation(angleStart);
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {

            }
        }
        if (LastPosY == 32) {
            _weaponSprite.setPosition(playerPosX + 25, playerPosY + 12);
            _weaponSprite.setRotation(0);
        }
        if (LastPosY == 16) {
            _weaponSprite.setPosition(playerPosX - 10, playerPosY + 40);
            _weaponSprite.setRotation(270);
        }
        if (LastPosY == 48) {
            _weaponSprite.setPosition(playerPosX + 15, playerPosY + 12);
            _weaponSprite.setRotation(320);
        }
        
    }

    if ()
        if (_weaponSprite.getRotation() >= 340 && _weaponSprite.getRotation() <= 345)
        {
            if (angleEnd >= angleStart)

            _weaponSprite.setRotation(angleStart);
            _weaponSprite.setOrigin(20, 30);
            angleStart += 5;
        }
    }
    window.draw(_weaponSprite);
}
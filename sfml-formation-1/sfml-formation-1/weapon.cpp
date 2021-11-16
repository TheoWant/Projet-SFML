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

void Weapon::Animate(RenderWindow& window, Texture& weaponTexture, int playerPosX, int playerPosY, int LastPosY) {
    if (hasWeapon == true){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(LastPosY == 0 or LastPosY == 32 or LastPosY == 48){
                _weaponSprite.setPosition(playerPosX + 25 , playerPosY + 12);
                _weaponSprite.setRotation(0);
            }
            else if (LastPosY == 16) {
                _weaponSprite.setPosition(playerPosX - 10, playerPosY + 40);
                _weaponSprite.setRotation(270);
            }
            window.draw(_weaponSprite);
        }
    }
}
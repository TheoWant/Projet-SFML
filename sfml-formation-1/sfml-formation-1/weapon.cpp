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
    _weaponSprite.scale(0, 0);
}

sf::Vector2f Weapon::getWeaponPosition()
{
    return _weaponSprite.getPosition();
}

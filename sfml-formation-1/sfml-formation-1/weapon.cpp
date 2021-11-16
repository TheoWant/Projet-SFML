#include <SFML/Graphics.hpp>
#include "weapon.h"
#include "player.h"
#include <iostream>


using namespace sf; 




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

void Weapon::setHasWeapon(bool b)
{
    b = true;
    hasWeapon = b;
}

sf::Vector2f Weapon::getWeaponPosition()
{
    return _weaponSprite.getPosition();
}

//void Weapon::attackAnim(bool anim, float angleStart, float angleEnd, int lastPosY)
//{
//    if (animation == true && angleEnd != angleStart && lastPosY == lastPosY) {
//        _weaponSprite.setOrigin(-10, -10);
//        angleStart += 0.3;
//        _weaponSprite.setRotation(angleStart);
//
//        if (angleStart >= angleEnd) {
//            angleStart = -20;
//            animation = false;
//        }
//    }
//}


void Weapon::Animate(RenderWindow& window, Texture& weaponTexture, Player& player, int LastPosY) {
    
    if (player.hasWeapon() == true){
        if(LastPosY == 0){
            _weaponSprite.setPosition(player.getPlayerPosition().x + 22 , player.getPlayerPosition().y + 12);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(340);
        }
        if(LastPosY == 32) {
            _weaponSprite.setPosition(player.getPlayerPosition().x + 25, player.getPlayerPosition().y + 12);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(0);
        }
        if (LastPosY == 16) {
            _weaponSprite.setPosition(player.getPlayerPosition().x - 10, player.getPlayerPosition().y + 40);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(270);
        }
        if (LastPosY == 48) {
            _weaponSprite.setPosition(player.getPlayerPosition().x + 15, player.getPlayerPosition().y + 12);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(320);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (LastPosY == 0)
            {
                animation = true;
                angleEnd = 120;
            }
            else if (LastPosY == 32)
            {
                animation = true;
                angleEnd = 40;
            }
            else if (LastPosY == 16)
            {
                animation = true;
                angleEnd = -240;
            }
            else if (LastPosY == 48)
            {
                animation = true;
                angleEnd = 290;
            }
        }
        
        if(animation == true && angleEnd != angleStartB && LastPosY == 0){ // Bottom animation
            _weaponSprite.setOrigin(-10, -10);
            angleStartB += 0.3;
            _weaponSprite.setRotation(angleStartB);

            if (angleStartB >= angleEnd) {
                angleStartB = -20;
                animation = false;
            }
        }

        if (animation == true && angleEnd != angleStartR && LastPosY == 32) { // Rigth animation
            _weaponSprite.setOrigin(-10, -10);
            angleStartR += 0.3;
            _weaponSprite.setRotation(angleStartR);

            if (angleStartR >= angleEnd) {
                angleStartR = -80;
                animation = false;
            }
        }

        if (animation == true && angleEnd != angleStartL && LastPosY == 16) {   // Left animation
            _weaponSprite.setOrigin(-10, 10);
            _weaponSprite.setPosition(player.getPlayerPosition().x + 20, player.getPlayerPosition().y + 40);
            angleStartL -= 0.3;
            _weaponSprite.setRotation(angleStartL);
            if (angleStartL <= angleEnd) {
                angleStartL = -120;
                animation = false;
            }
        }

        if (animation == true && angleEnd != angleStartT && LastPosY == 48) { // Bottom animation
            _weaponSprite.setOrigin(-10, -10);
            angleStartT += 0.3;
            _weaponSprite.setRotation(angleStartT);
            if (angleStartT >= angleEnd) {
                angleStartT = 170;
                animation = false;
            }

        }

    }
    window.draw(_weaponSprite);
}
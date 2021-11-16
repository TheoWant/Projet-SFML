#include <SFML/Graphics.hpp>
#include "weapon.h"
#include "player.h"
#include <iostream>


using namespace sf; 

bool hasWeapon = false;
bool attack = false;
float angleStartB = -20;    //Bottom
float angleStartT = 170;    //Top
float angleStartR = -80;    //Rigth
float angleStartL = -120;    //Left

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

bool animation = false;

void Weapon::Animate(RenderWindow& window, Texture& weaponTexture, int playerPosX, int playerPosY, int LastPosY) {
    
    if (hasWeapon == true){
        if(LastPosY == 0){
            _weaponSprite.setPosition(playerPosX + 22 , playerPosY + 12);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(340);
        }
        if (LastPosY == 32) {
            _weaponSprite.setPosition(playerPosX + 25, playerPosY + 12);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(0);
        }
        if (LastPosY == 16) {
            _weaponSprite.setPosition(playerPosX - 10, playerPosY + 40);
            _weaponSprite.setOrigin(0, 0);
            _weaponSprite.setRotation(270);
        }
        if (LastPosY == 48) {
            _weaponSprite.setPosition(playerPosX + 15, playerPosY + 12);
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
            _weaponSprite.setPosition(playerPosX + 20, playerPosY + 40);
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
        
        //std::cout << LastPosY << "\n";
        /*std::cout << _weaponSprite.getOrigin().x<< "," << _weaponSprite.getOrigin().y << "\n";*/
        window.draw(_weaponSprite);

    }
    window.draw(_weaponSprite);
}
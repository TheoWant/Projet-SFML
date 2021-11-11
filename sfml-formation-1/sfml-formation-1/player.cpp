#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;

void Player::loadPlayer(Texture& playerTexture)
{
    playerTexture.loadFromFile("characters.png");
    _playerSprite.setTexture(playerTexture);
    _playerSprite.setTextureRect(IntRect(48, 0, 16, 16));
    _playerSprite.scale(3, 3);
}

void Player::animate(int spritePosY)
{
    
    IntRect playerRect(_playerSprite.getTextureRect());

    playerRect.top = spritePosY;

    float elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 0.1f )
    {
        if (playerRect.left == 80)
        {
            playerRect.left = 48;
        }
        else
        {
            playerRect.left += 16;
        }

        _playerSprite.setTextureRect(playerRect);
        clock.restart();

    }

    

   /* int spriteSize = 16;

    anim.x += spriteSize;
    if (anim.x == 80)
    {
        anim.x = 48;
    }
    _playerSprite.setTextureRect(IntRect(anim.x, anim.y, spriteSize, spriteSize));*/

    
}

void Player::movePlayer()
{
    bool isMoving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        isMoving = true;
        this->animate(0);
        lastPosY = 0;
        _playerSprite.move(0, 0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        isMoving = true;
        this->animate(16);
        lastPosY = 16;
        _playerSprite.move(-0.2f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        isMoving = true;
        this->animate(32);
        lastPosY = 32;
        _playerSprite.move(0.2f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        isMoving = true;
        this->animate(48);
        lastPosY = 48;
        _playerSprite.move(0, -0.2f);
    }
    if (isMoving == false) {
        _playerSprite.setTextureRect(IntRect(64, lastPosY, 16, 16));
    }
}





void Player::drawPlayer(RenderWindow& window)
{
    window.draw(_playerSprite);
}
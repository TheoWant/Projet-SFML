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
    Clock clock;
    
    _playerSprite.setTextureRect(IntRect(48, spritePosY, 16, 16));
    
    IntRect playerRect(_playerSprite.getTextureRect());

    int elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 1.0f )
    {
        if (playerRect.left == 70)
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
}

void Player::movePlayer()
{
    /*enu Direction { Down, Left, Right, Up};
    Vector2i anim(1, Down);

    int spriteSize = 16;
    int spriteStartPosX = spriteSize * 3;
    int spriteEndPosX = spriteStartPosX + (spriteSize * 2);*/


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->animate(0);
        /*anim.y = Down;*/
        _playerSprite.move(0, 0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->animate(16);
        /*anim.y = Left;*/
        _playerSprite.move(-0.2f, 0);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->animate(32);
        /*anim.y = Right;*/
        _playerSprite.move(0.2f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->animate(48);
        /*anim.y = Up;*/
        _playerSprite.move(0, -0.2f);
    }

    /*anim.x++;
    if (anim.x * (spriteStartPosX) >= spriteSize * 2)
    {
        anim.x = 0;
    }

    _playerSprite.setTextureRect(IntRect(anim.x * spriteSize, anim.y * spriteSize, spriteSize, spriteSize));*/
}

void Player::drawPlayer(RenderWindow& window)
{
    window.draw(_playerSprite);
}
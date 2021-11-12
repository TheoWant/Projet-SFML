#include <SFML/Graphics.hpp>
#include "player.h"
#include "weapon.h"

using namespace sf;

void Player::loadPlayer(Texture& playerTexture)
{
    playerTexture.loadFromFile("characters.png");
    _playerSprite.setTexture(playerTexture);
    _playerSprite.setTextureRect(IntRect(48, 0, 16, 16));
    _playerSprite.scale(3, 3);
}


sf::Vector2f Player::getPlayerPosition()
{
    return _playerSprite.getPosition();
}


void Player::animate(int spritePosY)
{
    
    IntRect playerRect(_playerSprite.getTextureRect());

    playerRect.top = spritePosY;

    float elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 0.1f)
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


    
}

Vector2f Player::normalize(Vector2f vecteur)
{
    float length = std::sqrt(vecteur.x * vecteur.x + vecteur.y * vecteur.y);
    return vecteur / length;
}



void Player::movePlayer()
{
    bool isMoving = false;
    float deltaTime = movementClock.restart().asSeconds();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        isMoving = true;
        this->animate(0);
        lastPosY = 0;
        _playerSprite.move(0, _velocity * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        isMoving = true;
        this->animate(16);
        lastPosY = 16;
        _playerSprite.move(-_velocity * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        isMoving = true;
        this->animate(32);
        lastPosY = 32;
        _playerSprite.move(_velocity * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        isMoving = true;
        this->animate(48);
        lastPosY = 48;
        _playerSprite.move(0, -_velocity * deltaTime);
    }
    if (isMoving == false) {
        _playerSprite.setTextureRect(IntRect(64, lastPosY, 16, 16));
    }
}



void Player::drawPlayer(RenderWindow& window)
{
    window.draw(_playerSprite);
}
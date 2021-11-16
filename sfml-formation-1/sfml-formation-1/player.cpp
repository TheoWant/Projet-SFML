#include <SFML/Graphics.hpp>
#include "player.h"
#include "enemy.h"
#include "weapon.h"

using namespace std;
using namespace sf;

typedef Vector2f vec2;

void Player::loadPlayer(Texture& playerTexture)
{
    playerTexture.loadFromFile("characters.png");
    _playerSprite.setTexture(playerTexture);
    _playerSprite.setTextureRect(IntRect(48, 0, 16, 16));
    _playerSprite.scale(3, 3);
}


Vector2f Player::getPlayerPosition()
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

float Player::length(Vector2f vecteur)
{
    return std::sqrt(vecteur.x * vecteur.x + vecteur.y * vecteur.y);
}

Vector2f Player::normalize(Vector2f vecteur)
{
    float length = std::sqrt(vecteur.x * vecteur.x + vecteur.y * vecteur.y);
    return vecteur / length;
}


void Player::pickUp(Weapon& weapon)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        if (length(_playerSprite.getPosition() - weapon.getWeaponPosition()) <= 20)
        {
            bool setTrue = true;
            _weapon = new Weapon(weapon);
            _weapon->getSprite().setPosition(_playerSprite.getPosition().x, _playerSprite.getPosition().y);
        }
        else
        {
            std::cout << "weapon" << std::endl;
            std::cout << length(_playerSprite.getPosition() - weapon.getWeaponPosition()) << std::endl;
        }
    }
}



void Player::attack(Enemy& enemy)
{
    
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
        _playerSprite.move(0, _speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        isMoving = true;
        this->animate(32);
        lastPosY = 32;
        _playerSprite.move(_speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        isMoving = true;
        this->animate(16);
        lastPosY = 16;
        _playerSprite.move(-_speed * deltaTime, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        isMoving = true;
        this->animate(48);
        lastPosY = 48;
        _playerSprite.move(0, -_speed * deltaTime);
    }

    

    if (isMoving == false) {
        _playerSprite.setTextureRect(IntRect(64, lastPosY, 16, 16));
    }


    if (_playerSprite.getPosition().x < -10){
        _playerSprite.setPosition(-10, _playerSprite.getPosition().y);
    }
    if (_playerSprite.getPosition().y < 0) {
        _playerSprite.setPosition(_playerSprite.getPosition().x, 0);
    }
    if (_playerSprite.getPosition().x > 510) {
        _playerSprite.setPosition(510, _playerSprite.getPosition().y);
    }
    if (_playerSprite.getPosition().y > 332) {
        _playerSprite.setPosition(_playerSprite.getPosition().x, 332);
    }
}

void Player::Life(sf::RenderWindow& window) {
    sf::VertexArray quad(sf::Quads, 4);

    quad[0].position = sf::Vector2f(_playerSprite.getPosition().x, _playerSprite.getPosition().y - 25);
    quad[1].position = sf::Vector2f(_playerSprite.getPosition().x, _playerSprite.getPosition().y - 20);
    quad[2].position = sf::Vector2f(_playerSprite.getPosition().x + 45, _playerSprite.getPosition().y - 20);
    quad[3].position = sf::Vector2f(_playerSprite.getPosition().x + 45, _playerSprite.getPosition().y - 25);

    quad[0].color = sf::Color::Green;
    quad[1].color = sf::Color::Green;
    quad[2].color = sf::Color::Green;
    quad[3].color = sf::Color::Green;

    window.draw(quad);
}



void Player::drawPlayer(RenderWindow& window)
{
    window.draw(_playerSprite);
    
}
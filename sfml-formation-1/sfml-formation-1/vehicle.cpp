#include <SFML/Graphics.hpp>
#include "vehicle.h"

using namespace std;
using namespace sf;

typedef Vector2f vec2;

void Vehicle::loadVehicle(sf::Texture& vehicleTexture)
{
    vehicleTexture.loadFromFile("horse.png");
    _vehiculeSprite.setTexture(vehicleTexture);
    _vehiculeSprite.setTextureRect(IntRect(85, 0, 108, 60));
    _vehiculeSprite.setPosition(350, 50);
    _vehiculeSprite.scale(1.7, 1.7);
}

sf::FloatRect Vehicle::horseBounds() {
    return _vehiculeSprite.getGlobalBounds();
}

void Vehicle::animate(int spritePosY)
{
    IntRect vehicleTexture(_vehiculeSprite.getTextureRect());

    vehicleTexture.top = spritePosY;

    float elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 0.1f)
    {
        if (vehicleTexture.left == 80)
        {
            vehicleTexture.left = 48;
        }
        else
        {
            vehicleTexture.left += 16;
        }

        _vehiculeSprite.setTextureRect(vehicleTexture);
        clock.restart();

    }
}

float posRotate = 0;

void Vehicle::horseAnimate(bool playerOnHorse, int lastPosY) {
    if (playerOnHorse == true) {
        _vehiculeSprite.setTextureRect(IntRect(32, 0, 22, 60));
        bool isMoving = false;
        float deltaTime = movementClock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            isMoving = true;
            this->animate(0);
            lastPosY = 0;
            _vehiculeSprite.move(0, _speed * deltaTime);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            isMoving = true;
            this->animate(32);
            lastPosY = 32;
            posRotate += 0.1;
            _vehiculeSprite.setRotation(posRotate);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            isMoving = true;
            this->animate(16);
            lastPosY = 16;
            posRotate -= 0.1;
            _vehiculeSprite.setRotation(posRotate);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            isMoving = true;
            this->animate(48);
            lastPosY = 48;
            _vehiculeSprite.move(0, -_speed * deltaTime);
        }



        if (isMoving == false) {
            _vehiculeSprite.setTextureRect(IntRect(32, 0, 22, 60));
        }


        if (_vehiculeSprite.getPosition().x < -10) {
            _vehiculeSprite.setPosition(-10, _vehiculeSprite.getPosition().y);
        }
        if (_vehiculeSprite.getPosition().y < 0) {
            _vehiculeSprite.setPosition(_vehiculeSprite.getPosition().x, 0);
        }
        if (_vehiculeSprite.getPosition().x > 510) {
            _vehiculeSprite.setPosition(510, _vehiculeSprite.getPosition().y);
        }
        if (_vehiculeSprite.getPosition().y > 332) {
            _vehiculeSprite.setPosition(_vehiculeSprite.getPosition().x, 332);
        }
    }
}

void Vehicle::drawHorse(RenderWindow& window)
{
    window.draw(_vehiculeSprite);

}

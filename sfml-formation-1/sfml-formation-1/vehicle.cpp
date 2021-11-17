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

void Vehicle::horseAnimate(bool playerOnHorse) {
    if (playerOnHorse = true) {

    }
}

void Vehicle::drawHorse(RenderWindow& window)
{
    window.draw(_vehiculeSprite);

}

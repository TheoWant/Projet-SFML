#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Vehicle
{

public:
	void loadVehicle(sf::Texture& vehicleTexture);
	void drawHorse(sf::RenderWindow& window);
	sf::FloatRect horseBounds();
	void horseAnimate(bool playerOnHorse, int lastPosY);
	void animate(int spritePosY);
	void setTextureBack(sf::Texture& vehicleTexture) { return _vehiculeSprite.setTextureRect(IntRect(85, 0, 108, 60)); }
protected:
	sf::Sprite _vehiculeSprite;
	float _speed = 60.0f;
	sf::Clock clock;
	sf::Clock movementClock;
	sf::Time dt;
};


#pragma once
class Vehicle
{

public:
	void loadVehicle(sf::Texture& vehicleTexture);
	void drawHorse(sf::RenderWindow& window);
	sf::FloatRect horseBounds();
	void horseAnimate(bool playerOnHorse, int lastPosY);
	void animate(int spritePosY);
protected:
	sf::Sprite _vehiculeSprite;
	float _speed = 60.0f;
	sf::Clock clock;
	sf::Clock movementClock;
	sf::Time dt;
};


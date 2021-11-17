#pragma once
class Vehicle
{

public:
	void loadVehicle(sf::Texture& vehicleTexture);
	void drawHorse(sf::RenderWindow& window);
	sf::FloatRect horseBounds();
	void horseAnimate(bool playerOnHorse);
protected:
	sf::Sprite _vehiculeSprite;
};


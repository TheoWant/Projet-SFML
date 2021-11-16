#pragma once
class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);
	void pickUp();
	void TakeWeapon();
	sf::Vector2f getWeaponPosition();
	sf::Sprite weaponSprite();

protected:
	int _damage = 10;
	sf::Sprite _weaponSprite;



};


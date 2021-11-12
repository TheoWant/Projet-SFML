#pragma once
class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);

protected:
	int _damage = 10;
	sf::Sprite _weaponSprite;

};


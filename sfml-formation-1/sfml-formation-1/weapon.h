#pragma once
class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);
	
	sf::Vector2f getWeaponPosition();

protected:
	int _damage = 10;
	sf::Sprite _weaponSprite;



};


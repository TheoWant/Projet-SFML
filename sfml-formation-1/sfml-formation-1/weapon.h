#pragma once
class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);
	void pickUp();
	void Animate(sf::RenderWindow& window, sf::Texture& weaponTexture, int playerPosX, int playerPosY,int lastPosY);
	sf::Vector2f getWeaponPosition();

protected:
	int _damage = 10;
	sf::Sprite _weaponSprite;

};


#pragma once
class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);
	void pickUp();

	bool attack();

	void Animate(sf::RenderWindow& window, sf::Texture& weaponTexture, int playerPosX, int playerPosY,int lastPosY);
	sf::Vector2f getWeaponPosition();

	sf::Sprite getSprite() { return _weaponSprite; };

protected:
	int _damage = 10;

	int _attackSpeed = 10;

	sf::Sprite _weaponSprite;

	sf::Clock timer;
	sf::Time deltaTime;

	float attackTimer = 0;

	float angleStart = 0;
	float angleEnd = 90;
};


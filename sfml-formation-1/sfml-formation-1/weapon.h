#pragma once

class Player;

class Weapon
{
public:
	void loadWeapon(sf::Texture& texture);
	void drawWeapon(sf::RenderWindow& window);

	void pickUp();

	void setHasWeapon(bool b);
	bool getHasWeapon() { return hasWeapon; };

	bool attack();
	void attackAnim(bool anim, float angleStart, float angleEnd, int lastPosY);
	void Animate(sf::RenderWindow& window, sf::Texture& weaponTexture, Player& player, int LastPosY);
	sf::Vector2f getWeaponPosition();

	sf::Sprite getSprite() { return _weaponSprite; };

protected:
	int _damage = 10;

	sf::Sprite _weaponSprite;
	sf::Clock timer;
	sf::Time deltaTime;

	bool hasWeapon = false;
	float angleEnd;

	/*bool attack = false;*/
	float angleStartB = -20;    //Bottom
	float angleStartT = 170;    //Top
	float angleStartR = -80;    //Rigth
	float angleStartL = -120;    //Left

	float angleAddition = 0.3;
	
	bool animation = false;
};


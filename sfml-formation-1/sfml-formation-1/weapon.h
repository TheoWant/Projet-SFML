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
	sf::FloatRect getSwordBounds();
	bool attack();
	void attackAnim(bool anim, float angleStart, float angleEnd, int lastPosY);
	void Animate(sf::RenderWindow& window, sf::Texture& weaponTexture, Player& player, int LastPosY, bool playerOnHorse);
	sf::Vector2f getWeaponPosition();
	
	sf::Sprite getSprite() { return _weaponSprite; };

protected:
	int _damage = 10;

	sf::Sprite _weaponSprite;
	sf::Clock timer;
	sf::Time deltaTime;

	bool hasWeapon = false;
	double angleEnd = 0;

	/*bool attack = false;*/
	double angleStartB = -20;    //Bottom
	double angleStartT = 170;    //Top
	double angleStartR = -80;    //Rigth
	double angleStartL = -120;    //Left

	double angleAddition = 0.3;
	
	bool animation = false;
};


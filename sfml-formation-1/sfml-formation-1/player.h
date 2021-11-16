#pragma once
#include "weapon.h";

class Weapon;
class Sprite;
class Enemy;

class Player

{
public:
	void loadPlayer(sf::Texture& t);
	void drawPlayer(sf::RenderWindow& window);
	void movePlayer();

	/*bool hasWeapon() { return weapon != nullptr; };*/

	void pickUp(Weapon& weapon);

	void Life(sf::RenderWindow& window);
	void animate(int spritePosY);

	void attack(Enemy& enemy);

	float length(sf::Vector2f vecteur);

	sf::Vector2f getPlayerPosition();

	sf::Sprite getSprite() { return _playerSprite; };
	sf::Vector2f normalize(sf::Vector2f vecteur);
	int lastPosY = 0;
protected:

	float _speed = 60.0f;
	sf::Sprite _playerSprite;

	sf::Clock clock;
	sf::Clock movementClock;
	sf::Time dt;

	Weapon _weapon;
};


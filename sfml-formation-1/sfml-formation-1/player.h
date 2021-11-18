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
	sf::FloatRect getPlayerBounds();
	void pickUp(Weapon& weapon);
	bool hasWeapon = false;

	void Life(sf::RenderWindow& window, float playerHP);
	void animate(int spritePosY);

	void attack(Enemy& enemy);

	float length(sf::Vector2f vecteur);
	int getLastPosY() { return lastPosY; };
	sf::Vector2f getPlayerPosition();
	void setPlayerPosition(int NewX, int NewY);
	sf::Sprite getSprite() { return _playerSprite; };
	sf::Vector2f normalize(sf::Vector2f vecteur);
	
protected:

	float _speed = 60.0f;
	
	int lastPosY = 0;

	sf::Sprite _playerSprite;
	
	sf::Clock clock;
	sf::Clock movementClock;
	sf::Time dt;

	Weapon* _weapon = nullptr;
};


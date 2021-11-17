#pragma once
#include <iostream>


class Enemy
{
public:

	void loadEnemy(sf::Texture& t);
	void animate(int spritePosY);
	void moveEnemy();
	sf::FloatRect getEnemyBounds();
	void draw(sf::RenderWindow& window);
	
	float length(sf::Vector2f vecteur);
	sf::Vector2f normalize(sf::Vector2f vecteur);

	sf::Sprite getSprite() { return _enemySprite; };

protected:

	float _speed = 50.0f;

	int pauseTime = 2;

	bool _isMoving = true;

	sf::Sprite _enemySprite;

    sf::Vertex enemyVertex;

	sf::Clock animClock;
	sf::Clock movementClock;

	float time = 0;
	float pause = 0;

	sf::Clock timer;

	sf::Time delta;

	sf::Vector2f startPos{ 200, 100 };
	sf::Vector2f endPos{300 ,200};

	float _vecLength = length(endPos - startPos); 
	float travelTime = _vecLength / _speed;

	
};


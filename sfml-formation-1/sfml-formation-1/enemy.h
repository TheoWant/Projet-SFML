#pragma once
#include <iostream>


class Enemy
{
public:
	/*Enemy(std::string name, int velocity);
	~Enemy();*/

	void loadEnemy(sf::Texture& t);
	void animate(int spritePosY);
	void moveEnemy();
	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite getSprite() { return _enemySprite; };

protected:

	float _velocity = 0.002;
	int pauseTime = 2;
	sf::Sprite _enemySprite;

	sf::Vertex enemyVertex;

	sf::Clock clock;

	sf::Vector2f startPos{ 200, 100 };
	sf::Vector2f endPos{300 ,200};
};


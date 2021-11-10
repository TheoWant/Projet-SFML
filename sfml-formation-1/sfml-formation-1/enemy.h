#pragma once
#include <iostream>

class Enemy
{
public:
	/*Enemy(std::string name, int velocity);
	~Enemy();*/

	void loadEnemy(sf::Texture& t);
	void animate();

	void update(float delta);
	void draw(sf::RenderWindow& window);

	sf::Sprite getSprite() { return _enemySprite; };
protected:
	int _velocity = 0;
	sf::Sprite _enemySprite;
};


#include <SFML/Graphics.hpp>
#include "enemy.h"

using namespace sf;

void Enemy::loadEnemy(Texture& enemyTexture)
{
    enemyTexture.loadFromFile("characters.png");
    _enemySprite.setTexture(enemyTexture);
    _enemySprite.setTextureRect(IntRect(96, 64, 16, 16));
    _enemySprite.scale(3, 3);
    _enemySprite.setPosition(200, 100);
}


void Enemy::animate()
{
	

}

void Enemy::draw(RenderWindow& window)
{
    window.draw(_enemySprite);
}
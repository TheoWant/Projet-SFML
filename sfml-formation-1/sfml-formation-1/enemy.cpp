#include <SFML/Graphics.hpp>
#include "enemy.h"

using namespace sf;


void Enemy::loadEnemy(Texture& enemyTexture)
{
    enemyTexture.loadFromFile("characters.png");
    _enemySprite.setTexture(enemyTexture);
    _enemySprite.setTextureRect(IntRect(96, 64, 16, 16));
    _enemySprite.scale(3, 3);
    _enemySprite.setPosition(startPos.x, startPos.y);
}

Vector2f Enemy::normalize(Vector2f vecteur)
{
    float length = std::sqrt(vecteur.x * vecteur.x + vecteur.y * vecteur.y);
    return vecteur / length;
}

//void update(float delta)
//{
//    Vector2f enemyWay;
//    std::vector<Vector2f> coord = { Vector2f(200, 100), Vector2f(250, 150), Vector2f(300, 200) };
//}


void Enemy::moveEnemy()
{
    Vector2f enemyPos = _enemySprite.getPosition();
    Vector2f enemyNormalized = normalize(endPos - enemyPos);
    _isMoving = false;

    if (enemyPos.x >= endPos.x - 1 && enemyPos.y >= endPos.y - 1)
    {
        _isMoving = true;
        endPos.x = startPos.x;
        endPos.y = startPos.y;

        _enemySprite.move((enemyNormalized)*_velocity);
        this->animate(80);
    }

    if (enemyPos.x <= endPos.x + 1 && enemyPos.y <= endPos.y + 1)
    {
        _isMoving = true;
        endPos.x = 300;
        endPos.y = 200;

        _enemySprite.move((enemyNormalized)*_velocity);
        this->animate(96);
    }

    if (_isMoving == false)
    {

    }
}

void Enemy::animate(int spritePosY)
{
    IntRect enemyRect(_enemySprite.getTextureRect());

    enemyRect.top = spritePosY;

    float elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 0.3f)
    {
        if (enemyRect.left == 128)
        {
            enemyRect.left = 96;
        }
        else
        {
            enemyRect.left += 16;
        }

        _enemySprite.setTextureRect(enemyRect);
        clock.restart();

    }

}

void Enemy::draw(RenderWindow& window)
{
    window.draw(_enemySprite);
}
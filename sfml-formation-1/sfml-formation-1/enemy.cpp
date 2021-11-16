#include <SFML/Graphics.hpp>
#include "enemy.h"
#include <thread>
#include <chrono>


using namespace sf;


void Enemy::loadEnemy(Texture& enemyTexture)
{
    enemyTexture.loadFromFile("characters.png");
    _enemySprite.setTexture(enemyTexture);
    _enemySprite.setTextureRect(IntRect(96, 64, 16, 16));
    _enemySprite.scale(3, 3);
    _enemySprite.setPosition(startPos.x, startPos.y);
}

float Enemy::length(Vector2f vecteur)
{
    return std::sqrt(vecteur.x * vecteur.x + vecteur.y * vecteur.y);
}

Vector2f Enemy::normalize(Vector2f vecteur)
{
    float vectLength = length(vecteur);
    return vecteur / vectLength;
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


    float deltaTime = movementClock.restart().asSeconds();

    
    time += deltaTime;
    pause += deltaTime;

    if (_isMoving == true)
    {
        if (time > travelTime)
        {
            pause = 0;
            _isMoving = false;
            _speed = 0;
            this->animate(64);
        }

        if (enemyPos.x >= endPos.x && enemyPos.y >= endPos.y)
        {
            endPos.x = startPos.x;
            endPos.y = startPos.y;

            _enemySprite.move((enemyNormalized)*_speed * deltaTime);
            this->animate(80);
        }

        if (enemyPos.x <= endPos.x && enemyPos.y <= endPos.y)
        {
            endPos.x = 300;
            endPos.y = 200;

            _enemySprite.move((enemyNormalized)*_speed * deltaTime);
            this->animate(96);
        }
    }


    if (_isMoving == false && pause > 2)
    {   
        time = 0;
        _isMoving = true;
        _speed = 50.0f;
    }
    else 
    {
        this->animate(64);
    }
}

void Enemy::animate(int spritePosY)
{
    IntRect enemyRect(_enemySprite.getTextureRect());

    enemyRect.top = spritePosY;

    float elapsedTimeInSeconds = animClock.getElapsedTime().asSeconds();

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
        animClock.restart();

    }

}

void Enemy::draw(RenderWindow& window)
{
    window.draw(_enemySprite);
}
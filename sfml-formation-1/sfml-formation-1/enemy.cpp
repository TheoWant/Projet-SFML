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

void Enemy::moveEnemy()
{
    
    Vector2f enemyPos = _enemySprite.getPosition();
    
    //Vector normalization
    float norme = std::sqrt(enemyPos.x * endPos.x + enemyPos.y * endPos.y);
    Vector2f enemyDirection = enemyPos / norme;


    if ( enemyPos.x >= endPos.x -2 && enemyPos.y >= endPos.y - 2)
    {
        endPos.x = startPos.x;
        endPos.y = startPos.y;
        
        _enemySprite.move((endPos.x - enemyPos.x) * _velocity, (endPos.y - enemyPos.y)* _velocity );
        this->animate(80);

        std::cout << "in if";
        std::cout << "x = " << enemyPos.x << std::endl;
        std::cout << "y = " << enemyPos.y << std::endl;

        std::cout << "endpos x = " << endPos.x << std::endl;
        std::cout << "endpos y = " << endPos.y << std::endl;
    }

    if (enemyPos.x <= endPos.x + 2 && enemyPos.y <= endPos.y + 2)
    {
        endPos.x = 300;
        endPos.y = 200;

        _enemySprite.move((endPos.x - enemyPos.x) * _velocity, (endPos.y - enemyPos.y) * _velocity);
        this->animate(96);
        
        std::cout << "in else if\n";
        std::cout << "x = " << enemyPos.x << std::endl;
        std::cout << "y = " << enemyPos.y << std::endl;

        std::cout << "endpos x = " << endPos.x << std::endl;
        std::cout << "endpos y = " << endPos.y << std::endl;
    }
}

void Enemy::animate(int spritePosY)
{
    IntRect enemyRect(_enemySprite.getTextureRect());

    enemyRect.top = spritePosY;

    float elapsedTimeInSeconds = clock.getElapsedTime().asSeconds();

    if (elapsedTimeInSeconds > 0.1f)
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
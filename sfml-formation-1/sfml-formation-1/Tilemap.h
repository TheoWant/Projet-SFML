#pragma once
#include <vector>
using namespace std;

class Tilemap
{
public:
    //vector<sf::Sprite> loadLevel(sf::Texture &t);
    void loadLevel(sf::Texture& t);
    void draw(sf::RenderWindow& window);
protected:
    std::vector<sf::Sprite> Tiles, TilesBack;
};
#pragma once

class Player

{
public:
	void loadPlayer(sf::Texture& t);
	void drawPlayer(sf::RenderWindow& window);
	void movePlayer();
	void Life(sf::RenderWindow& window);
	void animate(int spritePosY);

	sf::Sprite getSprite() { return _playerSprite; }
	

protected:
	int velocity;
	int lastPosY = 0;
	sf::Sprite _playerSprite;
	sf::Clock clock;
};


#pragma once

class Player

{
public:
	void loadPlayer(sf::Texture& t);
	void drawPlayer(sf::RenderWindow& window);
	void movePlayer();
	void animate(int spritePosY);

	sf::Sprite getSprite() { return _playerSprite; }
	

protected: 
	sf::Sprite _playerSprite;
};


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
	int velocity;
	sf::Sprite _playerSprite;
	sf::Clock clock;
	sf::Vector2i anim;
};


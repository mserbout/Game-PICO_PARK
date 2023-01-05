#include <SFML/Graphics.hpp>

#include "Player.h"

namespace sf {
	class RenderWindow;
	class Event;
}

Player::Player() {

};

Player::~Player() {

};

void Player::inputs(const sf::Time& deltaTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		physics.location.x += speed * deltaTime.asSeconds();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		physics.location.x -= speed * deltaTime.asSeconds();
	}
	if (!isJumping) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			physics.velocity.y = -jumpSpeed;
			isJumping = true;
		}
	}


}

void Player::tick(const sf::Time& deltaTime) {
	physics.tick(deltaTime);

	const float border = WINDOW_SIZE_Y - sprite.getTexture()->getSize().y;

	if (physics.location.y > border)
	{
		physics.location.y = border;
		physics.velocity.y = 0;
		isJumping = false;

	}
}

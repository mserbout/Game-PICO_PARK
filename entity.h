#pragma once
#include <SFML/Graphics.hpp>
#include"physics.h"

namespace sf {
	class RenderWindow;
	class Time;

}
class Entity {

protected:
	sf::Sprite sprite;
public:
	Physics physics;
	vector2D size{ 100,100 };
public:
	Entity() {};
	virtual ~Entity() = default;

	void setSprite(const sf::Texture& texture)
	{

		sprite = sf::Sprite(texture);
		const sf::Vector2u& texSize = texture.getSize();
		size = vector2D(texSize.x, texSize.y);

	};


	void draw(sf::RenderWindow& window)
	{

		sprite.setPosition(physics.location.x, physics.location.y);
		window.draw(sprite);
	};


	bool iscollision(const Entity& entity)
	{
		return physics.location.x < entity.physics.location.x + entity.size.x
			&& entity.physics.location.x < physics.location.x + size.x

			&& physics.location.y < entity.physics.location.y + entity.size.y
			&& entity.physics.location.y < physics.location.y + size.y;

		// return xMin1 < x  xMax2 && xMin2 <xMax1
	}

	virtual void tick(const sf::Time& deltaTime) = 0;

};

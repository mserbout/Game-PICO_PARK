#pragma once
#include"entity.h"

class Projectile :public Entity {
private:

public:
	float speed = -500.f;
	Projectile() {

	};

	~Projectile() = default;


	void tick(const sf::Time& deltaTime) override
	{
		// constexpr float size = 50.f;

		const sf::Vector2u& textureSize = sprite.getTexture()->getSize();

		size = vector2D(50, 50);


		sprite.setScale(size.x / float(textureSize.x), size.y / float(textureSize.y));


		physics.velocity.x = speed * deltaTime.asSeconds();
		//physics.tick(deltaTime);
		physics.location.x += physics.velocity.x;
	};


};

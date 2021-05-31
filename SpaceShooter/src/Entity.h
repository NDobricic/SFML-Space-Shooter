#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	class Entity
	{
	protected:
		sf::Sprite* sprite;

	public:
		void SetPosition(const sf::Vector2f& position);
		const sf::Vector2f Position() const;
		//void SetRotation(float rotation);
		//float Rotation() const;
		void SetScale(const sf::Vector2f factors);
		const sf::Vector2f Scale() const;
		const sf::Vector2f Size() const;

		virtual void Start() { }
		virtual void Update(float deltaTime) { }
		virtual const sf::Sprite& GetSprite();
	};
}
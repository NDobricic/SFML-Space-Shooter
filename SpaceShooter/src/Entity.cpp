#include "Entity.h"

namespace ss
{
	void Entity::SetPosition(const sf::Vector2f& position)
	{
		sprite->setPosition(position);
	}

	const sf::Vector2f Entity::Position() const
	{
		return sprite->getPosition();
	}

	//void Entity::SetRotation(float rotation)
	//{
	//	sprite->setRotation(rotation);
	//}

	//float Entity::Rotation() const
	//{
	//	return sprite->getRotation();
	//}

	void Entity::SetScale(const sf::Vector2f factors)
	{
		sprite->setScale(factors);
	}

	const sf::Vector2f Entity::Scale() const
	{
		return sprite->getScale();
	}

	const sf::Vector2f Entity::Size() const
	{
		return sf::Vector2f(sprite->getTextureRect().width * sprite->getScale().x,
							sprite->getTextureRect().height * sprite->getScale().y);
	}

	const sf::Sprite& Entity::GetSprite()
	{
		return *sprite;
	}
}
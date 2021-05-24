#include "Player.h"

namespace ss
{
	Player::Player()
		: anim("res/sprites/player_sheet.png", 32, 32, 8)
	{
		anim.SetLoopMode(ss::AnimationLoopMode::Reverse);
		anim.SetSpeed(5);
	}

	void Player::Update(float deltaTime)
	{
		anim.Update(deltaTime);
	}

	const sf::Sprite& Player::GetSprite()
	{
		return anim;
	}
}
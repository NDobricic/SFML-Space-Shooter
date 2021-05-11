#include "AnimatedSprite.h"

namespace ss
{
	AnimatedSprite::AnimatedSprite(const std::string& spriteSheetPath, int width, int height, int numFrames, float duration, int offsetX, int offsetY)
	{
		Initialize(spriteSheetPath, width, height, numFrames, duration, offsetX, offsetY);
	}

	AnimatedSprite::AnimatedSprite(sf::Texture spriteSheetTexture, int width, int height, int numFrames, float duration, int offsetX, int offsetY)
	{
		Initialize(spriteSheetTexture, width, height, numFrames, duration, offsetX, offsetY);
	}

	void AnimatedSprite::Initialize(const std::string& spriteSheetPath, int width, int height, int numFrames, float duration, int offsetX, int offsetY)
	{
		sf::Texture tex;
		tex.loadFromFile(spriteSheetPath);

		Initialize(tex, width, height, numFrames, duration, offsetX, offsetY);
	}

	void AnimatedSprite::Initialize(sf::Texture spriteSheetTexture, int width, int height, int numFrames, float duration, int offsetX, int offsetY)
	{
		sheet = spriteSheetTexture;
		sprite.setTexture(sheet);

		w = width;
		h = height;

		offX = offsetX;
		offY = offsetY;

		this->numFrames = numFrames;
		this->duration = duration;

		time = 0.0f;
		speed = 1.0f;

		loopMode = AnimationLoopMode::Loop;
	}

	void AnimatedSprite::SetSpeed(float speed)
	{
		this->speed = speed;
	}

	void AnimatedSprite::SetLoopMode(const AnimationLoopMode& mode)
	{
		loopMode = mode;
	}

	void AnimatedSprite::Update(float deltaTime)
	{
		time = time + deltaTime * speed;

		if (time >= duration || time < 0)
		{
			switch (loopMode)
			{
			case ss::AnimationLoopMode::Loop:
				time = fmod(time + deltaTime * speed, duration);
				break;
			case ss::AnimationLoopMode::NoLoop:
				time = duration * 0.999f;
				break;
			case ss::AnimationLoopMode::Reverse:
				speed = -speed;
				if (time >= duration)
					time = duration - (time - duration);
				else
					time = -time;
				break;
			default:
				break;
			}
		}
	}

	const sf::Sprite& AnimatedSprite::GetSprite()
	{
		int currentFrame = time / duration * numFrames;

		int left = offX + w * currentFrame;
		int top = offY;

		sprite.setTextureRect(sf::IntRect(left, top, w, h));
		return sprite;
	}
}
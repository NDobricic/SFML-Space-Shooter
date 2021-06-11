#include "AnimatedSprite.h"

namespace ss
{
	AnimatedSprite::AnimatedSprite(const std::string& spriteSheetPath, int width, int height, int numFrames, int offsetX, int offsetY)
		: w(width), h(height), numFrames(numFrames), offX(offsetX), offY(offsetY)
	{
		sf::Texture* tex = new sf::Texture;
		tex->loadFromFile(spriteSheetPath);

		setTexture(*tex);

		setTextureRect(sf::IntRect(offX, offY, w, h));
	}

	AnimatedSprite::AnimatedSprite(sf::Texture spriteSheetTexture, int width, int height, int numFrames, int offsetX, int offsetY)
		: w(width), h(height), numFrames(numFrames), offX(offsetX), offY(offsetY)
	{
		setTexture(spriteSheetTexture);

		setTextureRect(sf::IntRect(offX, offY, w, h));
	}

	void AnimatedSprite::SetSpeed(float value)
	{
		this->speed = value;
	}

	void AnimatedSprite::SetLoopMode(const AnimationLoopMode& mode)
	{
		loopMode = mode;
	}

	void AnimatedSprite::Update(float deltaTime)
	{
		time = time + deltaTime * speed;

		if (time >= numFrames || time < 0)
		{
			switch (loopMode)
			{
			case ss::AnimationLoopMode::Loop:
				time = fmod(time, numFrames);
				break;
			case ss::AnimationLoopMode::NoLoop:
				time = numFrames * 0.999f;
				finished = true;
				break;
			case ss::AnimationLoopMode::Reverse:
				speed = -speed;
				if (time >= numFrames)
					time = numFrames - (time - numFrames);
				else
					time = -time;
				break;
			default:
				break;
			}
		}

		int currentFrame = (int)time;

		int left = offX + w * currentFrame;
		int top = offY;

		setTextureRect(sf::IntRect(left, top, w, h));
	}

	bool AnimatedSprite::IsFinished()
	{
		return finished;
	}
}
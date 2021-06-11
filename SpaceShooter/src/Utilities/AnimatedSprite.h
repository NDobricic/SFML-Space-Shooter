#pragma once

#include <SFML/Graphics.hpp>

namespace ss
{
	enum class AnimationLoopMode
	{
		Loop,
		NoLoop,
		Reverse
	};

	class AnimatedSprite : public sf::Sprite
	{
	private:
		int w, h;
		int offX, offY;

		int numFrames;
		float time = 0.0;
		float speed = 1.0;

		AnimationLoopMode loopMode = AnimationLoopMode::Loop;

		bool finished = false;

	public:
		AnimatedSprite(const std::string& spriteSheetPath, int width, int height, int numFrames, int offsetX = 0, int offsetY = 0);
		AnimatedSprite(sf::Texture spriteSheetTexture, int width, int height, int numFrames, int offsetX = 0, int offsetY = 0);

		void SetSpeed(float speed);
		void SetLoopMode(const AnimationLoopMode& mode);
		void Update(float deltaTime);

		bool IsFinished();
	};
}
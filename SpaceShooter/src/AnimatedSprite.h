#pragma once

#include <SFML/Graphics.hpp>
#include <string>

namespace ss
{
	enum class AnimationLoopMode
	{
		Loop,
		NoLoop,
		Reverse
	};

	class AnimatedSprite
	{
	private:
		sf::Texture sheet;

		int w, h;
		int offX, offY;

		int numFrames;
		float time;
		float duration;
		float speed;

		sf::Sprite sprite;
		AnimationLoopMode loopMode;

	public:
		AnimatedSprite(const std::string& spriteSheetPath, int width, int height, int numFrames, float duration, int offsetX = 0, int offsetY = 0);
		AnimatedSprite(sf::Texture spriteSheetTexture, int width, int height, int numFrames, float duration, int offsetX = 0, int offsetY = 0);

		void Initialize(const std::string& spriteSheetPath, int width, int height, int numFrames, float duration, int offsetX = 0, int offsetY = 0);
		void Initialize(sf::Texture spriteSheetTexture, int width, int height, int numFrames, float duration, int offsetX = 0, int offsetY = 0);

		void SetSpeed(float speed);
		void SetLoopMode(const AnimationLoopMode& mode);
		void Update(float deltaTime);

		const sf::Sprite& GetSprite();
	};
}
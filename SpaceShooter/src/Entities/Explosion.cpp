#include "Explosion.h"

#include"../Scenes/SceneManager.h"

namespace ss
{
	Explosion::Explosion()
		:anim("res/sprites/explosion_long.png", 32, 32, 14)
	{
		sprite = &anim;

		anim.SetSpeed(25);
		anim.SetLoopMode(AnimationLoopMode::NoLoop);
		anim.setScale(2, 2);
	}

	void Explosion::Update(float deltaTime)
	{
		if (anim.IsFinished())
			SceneManager::CurrentScene()->DestroyObject(this);
		else
			anim.Update(deltaTime);
	}
}
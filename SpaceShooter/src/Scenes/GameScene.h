#pragma once

#include "Scene.h"

namespace ss
{
	class GameScene : public Scene
	{
		virtual void Load() override;
		virtual void Unload() override;
	};
}
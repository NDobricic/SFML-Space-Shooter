#pragma once

#include "Scene.h"

namespace ss
{
	class MainMenuScene : public Scene
	{
		virtual void Load() override;
		virtual void UserUpdate() override;
	};
}
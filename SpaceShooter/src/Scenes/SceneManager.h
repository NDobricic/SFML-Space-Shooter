#pragma once

#include "Scene.h"

namespace ss
{
	class SceneManager
	{
	private:
		static Scene* currentScene;
	public:
		static Scene* CurrentScene();

		template<typename T>
		static void LoadScene()
		{
			T* objectToLoad = new T;
			Scene* newScene = dynamic_cast<Scene*>(objectToLoad);
			if (newScene == nullptr)
			{
				delete objectToLoad;
				return;
			}

			if (currentScene != nullptr)
			{
				currentScene->Unload();
				delete currentScene;
			}

			newScene->Load();

			currentScene = newScene;
		}
	};
}
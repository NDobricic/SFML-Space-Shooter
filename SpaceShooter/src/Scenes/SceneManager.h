#pragma once

#include "Scene.h"

namespace ss
{
	class SceneManager
	{
	private:
		static Scene* currentScene;
		static Scene* sceneToLoad;

	public:
		static Scene* CurrentScene();

		template<typename T>
		static void ChangeScene()
		{
			T* objectToLoad = new T;
			Scene* newScene = dynamic_cast<Scene*>(objectToLoad);
			if (newScene == nullptr)
			{
				delete objectToLoad;
				return;
			}

			sceneToLoad = newScene;

			if (currentScene != nullptr)
			{
				currentScene->Unload();
			}
			else
				FinishSceneChange();
		}

		static void FinishSceneChange()
		{
			delete currentScene;

			sceneToLoad->Load();

			currentScene = sceneToLoad;
		}
	};
}
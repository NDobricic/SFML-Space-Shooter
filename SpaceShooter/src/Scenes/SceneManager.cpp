#include "SceneManager.h"

namespace ss
{
	Scene* SceneManager::currentScene = nullptr;
	Scene* SceneManager::sceneToLoad = nullptr;

	Scene* SceneManager::CurrentScene()
	{
		return currentScene;
	}

	//template <typename T>
	//void SceneManager::LoadScene()
	//{
	//	T* objectToLoad = new T;
	//	Scene* newScene = dynamic_cast<Scene*>(objectToLoad);
	//	if (newScene == nullptr)
	//	{
	//		delete objectToLoad;
	//		return;
	//	}

	//	currentScene->Unload();
	//	delete currentScene;

	//	newScene->Load();
	//	currentScene = newScene;
	//}
}
#include "pch.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "DevScene.h"
void SceneMgr::Init()
{
}

void SceneMgr::Update()
{
	if (_scene)
		_scene->Update();
}

void SceneMgr::Render(HDC hdc)
{
	if (_scene)
		_scene->Render(hdc);
}

void SceneMgr::Clear()
{
	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}
}

void SceneMgr::ChangeScene(SceneType sceneType)
{
	if (_sceneType == sceneType)
		return;

	Scene* newScene = nullptr;

	switch (sceneType)
	{
		{
			case SceneType::DevScene:
				newScene = new DevScene();
				break;
			case SceneType::EditScene:

				break;
			case SceneType::GameScene:

				break;
			case SceneType::MenuScene:

				break;
		}
	}

	if (_scene)
	{
		delete _scene;
		_scene = nullptr;
	}

	_scene = newScene;
	_sceneType = sceneType;

	newScene->Init();
}

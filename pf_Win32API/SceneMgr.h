#pragma once
class Scene;

enum class SceneType
{
	None,
	DevScene,
	GameScene,
	EditScene,
	MenuScene,
};

class SceneMgr
{
	DECLARE_SINGLE(SceneMgr);

public:
	void Init();
	void Update();
	void Render(HDC hdc);

	void Clear();

public:
	void ChangeScene(SceneType sceneType);
	Scene* GetCurrentScene() { return _scene; }

private:
	Scene* _scene = nullptr;
	SceneType _sceneType = SceneType::None;
};


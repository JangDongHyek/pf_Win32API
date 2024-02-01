#include "pch.h"
#include "DevScene.h"
#include "ObjectMgr.h"
#include "Player.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	Player* player = GET_SINGLE(ObjectMgr)->CreatObject<Player>();
	player->SetPos(Pos(200,200));
	
	GET_SINGLE(ObjectMgr)->Add(player);
}

void DevScene::Update()
{
	const std::vector<Object*> objects = GET_SINGLE(ObjectMgr)->GetObjects();
	for (Object* object : objects)
	{
		object->Update();
	}
}

void DevScene::Render(HDC hdc)
{
	const std::vector<Object*> objects = GET_SINGLE(ObjectMgr)->GetObjects();
	for (Object* object : objects)
	{
		object->Render(hdc);
	}
}

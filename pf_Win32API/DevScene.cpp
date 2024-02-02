#include "pch.h"
#include "DevScene.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ResourceMgr.h"
#include "Texture.h"
#include "Sprite.h"

DevScene::DevScene()
{
}

DevScene::~DevScene()
{
}

void DevScene::Init()
{
	GET_SINGLE(ResourceMgr)->LoadTexture(L"Stage01", L"Sprite\\Map\\Stage01.bmp");
	GET_SINGLE(ResourceMgr)->LoadTexture(L"Potion", L"Sprite\\UI\\Mp.bmp");
	GET_SINGLE(ResourceMgr)->LoadTexture(L"PlayerDown", L"Sprite\\Player\\PlayerDown.bmp",RGB(128,128,128));
	GET_SINGLE(ResourceMgr)->LoadTexture(L"PlayerUp", L"Sprite\\Player\\PlayerUp.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceMgr)->LoadTexture(L"PlayerLeft", L"Sprite\\Player\\PlayerLeft.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceMgr)->LoadTexture(L"PlayerRight", L"Sprite\\Player\\PlayerRight.bmp", RGB(128, 128, 128));
	GET_SINGLE(ResourceMgr)->LoadTexture(L"Start", L"Sprite\\UI\\Start.bmp");
	GET_SINGLE(ResourceMgr)->LoadTexture(L"Edit", L"Sprite\\UI\\Edit.bmp");
	GET_SINGLE(ResourceMgr)->LoadTexture(L"Exit", L"Sprite\\UI\\Exit.bmp");

	Texture* texture = GET_SINGLE(ResourceMgr)->GetTexture(L"Start");
	GET_SINGLE(ResourceMgr)->CreateSprite(L"Start_On", texture, 150, 0, 150, 150);
}

void DevScene::Update()
{
	
}

void DevScene::Render(HDC hdc)
{
	//Texture
	//Texture* texture = GET_SINGLE(ResourceMgr)->GetTexture(L"Stage01");
	//::BitBlt(hdc, 0, 0, GWinSizeX, GWinSizeY, sprite->GetDC(), 0, 0, SRCCOPY);

	//Sprite
	Sprite* sprite = GET_SINGLE(ResourceMgr)->GetSprite(L"Start_On");
	::BitBlt(hdc, 0, 0, GWinSizeX, GWinSizeY, 
		sprite->GetDC(), sprite->GetPos().x, sprite->GetPos().y, SRCCOPY);
	
}

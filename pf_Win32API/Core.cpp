#include "pch.h"
#include "Core.h"
#include "InputMgr.h"
#include "TimeMgr.h"

Core::Core()
{
}

Core::~Core()
{
}

void Core::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_hdc = ::GetDC(_hwnd);

	// ½Ì±ÛÅæ ¸Å´ÏÀúµé ÃÊ±âÈ­
	GET_SINGLE(InputMgr)->Init(_hwnd);
	GET_SINGLE(TimeMgr)->Init();
}

void Core::Update()
{
	// ½Ì±ÛÅæ ¸Å´ÏÀúµé ¾÷µ¥ÀÌÆ®
	GET_SINGLE(InputMgr)->Update();
	GET_SINGLE(TimeMgr)->Update();

	//test
	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::A))
		_pos.x -= 1;
}

void Core::Render()
{
	::Rectangle(_hdc, _pos.x, _pos.y, 400, 400);

	uint32 fps = GET_SINGLE(TimeMgr)->GetFPS();
	float deltaTime = GET_SINGLE(TimeMgr)->GetDeltaTime();

	std::wstring str = std::format(L"FPS({0}), DT({1})", fps, deltaTime);
	::TextOut(_hdc, 550, 10, str.c_str(), static_cast<int32>(str.size()));
}

#include "pch.h"
#include "Core.h"
#include "InputMgr.h"

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
}

void Core::Update()
{
	// ½Ì±ÛÅæ ¸Å´ÏÀúµé ¾÷µ¥ÀÌÆ®
	GET_SINGLE(InputMgr)->Update();

	//test
	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::A))
		_pos.x -= 1;
}

void Core::Render()
{
	::Rectangle(_hdc, _pos.x, _pos.y, 400, 400);
}

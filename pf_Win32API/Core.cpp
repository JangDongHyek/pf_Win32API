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

	// �̱��� �Ŵ����� �ʱ�ȭ
	GET_SINGLE(InputMgr)->Init(_hwnd);
}

void Core::Update()
{
	// �̱��� �Ŵ����� ������Ʈ
	GET_SINGLE(InputMgr)->Update();

	//test
	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::A))
		_pos.x -= 1;
}

void Core::Render()
{
	::Rectangle(_hdc, _pos.x, _pos.y, 400, 400);
}

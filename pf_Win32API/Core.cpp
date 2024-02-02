#include "pch.h"
#include "Core.h"
#include "InputMgr.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "ResourceMgr.h"

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

	::GetClientRect(hwnd, &_rect);
	
	_hdcBack = ::CreateCompatibleDC(_hdc);
	_bmpBack = ::CreateCompatibleBitmap(_hdc, _rect.right, _rect.bottom);

	//DC�� �����ɶ� ������Ʈ���� ����ä�� �����ǰ� SelectObject ��ȯ���� ������ ����ϰ��ִ�
	// Object���� ��ȯ�Ǳ⋚���� �װ� ��ȯ�ȴ�
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	// �̱��� �Ŵ����� �ʱ�ȭ
	GET_SINGLE(InputMgr)->Init(_hwnd);
	GET_SINGLE(TimeMgr)->Init();
	GET_SINGLE(SceneMgr)->Init();
	GET_SINGLE(ResourceMgr)->Init(_hwnd, fs::path(L"C:\\c++\\pf_Win32API\\Resources"));

	GET_SINGLE(SceneMgr)->ChangeScene(SceneType::DevScene);
}

void Core::Update()
{
	// �̱��� �Ŵ����� ������Ʈ
	GET_SINGLE(InputMgr)->Update();
	GET_SINGLE(TimeMgr)->Update();
	GET_SINGLE(SceneMgr)->Update();
	
}

void Core::Render()
{
	uint32 fps = GET_SINGLE(TimeMgr)->GetFPS();
	float deltaTime = GET_SINGLE(TimeMgr)->GetDeltaTime();

	std::wstring str = std::format(L"FPS({0}), DT({1})", fps, deltaTime);
	::TextOut(_hdcBack, 550, 10, str.c_str(), static_cast<int32>(str.size()));

	GET_SINGLE(SceneMgr)->Render(_hdcBack);

	::BitBlt(_hdc, 0, 0, _rect.right, _rect.bottom, _hdcBack, 0, 0, SRCCOPY);
	::PatBlt(_hdcBack, 0, 0, _rect.right, _rect.bottom, WHITENESS);
}

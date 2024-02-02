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

	//DC가 생성될때 작은비트맵을 가진채로 생성되고 SelectObject 반환값은 이전에 사용하고있는
	// Object들이 반환되기떄문에 그게 반환된다
	HBITMAP prev = (HBITMAP)::SelectObject(_hdcBack, _bmpBack);
	::DeleteObject(prev);

	// 싱글톤 매니저들 초기화
	GET_SINGLE(InputMgr)->Init(_hwnd);
	GET_SINGLE(TimeMgr)->Init();
	GET_SINGLE(SceneMgr)->Init();
	GET_SINGLE(ResourceMgr)->Init(_hwnd, fs::path(L"C:\\c++\\pf_Win32API\\Resources"));

	GET_SINGLE(SceneMgr)->ChangeScene(SceneType::DevScene);
}

void Core::Update()
{
	// 싱글톤 매니저들 업데이트
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

#include "pch.h"
#include "InputMgr.h"

void InputMgr::Init(HWND hwnd)
{
	_hwnd = hwnd;
	_states.resize(KEY_TYPE_COUNT, KeyState::None);
	int a = 0;
}

void InputMgr::Update()
{
	BYTE asciiKeys[KEY_TYPE_COUNT] = {};
	if (::GetKeyboardState(asciiKeys) == false)
		return;


	for (int key = 0; key < KEY_TYPE_COUNT; key++)
	{
		KeyState& state = _states[key];
		// 키가 눌려있으면
		if (asciiKeys[key] & 0x80)
		{
			// 이전 업데이트에 눌려있었던거라면
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			// 이전 업데이트에 안눌려있던거라면
			else
				state = KeyState::Down;
		}
		// 키가 안눌려있으면
		else
		{
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Up;
			else
				state = KeyState::None;
		}
	}


	// Mouse 
	::GetCursorPos(&_mousePos);
}

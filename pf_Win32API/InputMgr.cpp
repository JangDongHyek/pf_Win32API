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
		// Ű�� ����������
		if (asciiKeys[key] & 0x80)
		{
			// ���� ������Ʈ�� �����־����Ŷ��
			if (state == KeyState::Press || state == KeyState::Down)
				state = KeyState::Press;
			// ���� ������Ʈ�� �ȴ����ִ��Ŷ��
			else
				state = KeyState::Down;
		}
		// Ű�� �ȴ���������
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

#pragma once

enum class KeyType
{
	LeftMouse = VK_LBUTTON,
	RightMouse = VK_RBUTTON,

	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT,

	Q = 'Q', W = 'W', E = 'E', R = 'R',
	A = 'A', S = 'S', D = 'D', F = 'F',

	Space = VK_SPACE
};

enum class KeyState
{
	None, // 아무것도 아닌상태
	Down, // 지금 막 눌렸을떄
	Press, // 누르고있는 상태
	Up, // 눌렀다가 막 뗀 상태
	End // 데이터의 끝을 알리는 부분
};

enum
{
	// UINT8_MAX : 1바이트 크기의 양수만 이니까 255
	// ascii코드가 1바이트이니까 1바이트의 정수 맥스치를 받아와 설정
	KEY_TYPE_COUNT = static_cast<unsigned __int32>(UINT8_MAX) + 1, 
	KEY_STATE_COUNT = static_cast<unsigned __int32>(KeyState::End)
};




class InputMgr
{
	DECLARE_SINGLE(InputMgr);

public:
	void Init(HWND hwnd);
	void Update();

	bool GetButtonDown(KeyType key) { return GetState(key) == KeyState::Down; }
	bool GetButtonPress(KeyType key) { return GetState(key) == KeyState::Press; }
	bool GetButtonUp(KeyType key) { return GetState(key) == KeyState::Up; }
	POINT GetMousePos() { return _mousePos; }

private:
	KeyState GetState(KeyType key) { return _states[static_cast<unsigned __int16>(key)]; }

private:
	HWND _hwnd = 0;
	std::vector<KeyState> _states;
	POINT _mousePos;
};


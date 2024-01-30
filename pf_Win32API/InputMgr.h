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
	None, // �ƹ��͵� �ƴѻ���
	Down, // ���� �� ��������
	Press, // �������ִ� ����
	Up, // �����ٰ� �� �� ����
	End // �������� ���� �˸��� �κ�
};

enum
{
	// UINT8_MAX : 1����Ʈ ũ���� ����� �̴ϱ� 255
	// ascii�ڵ尡 1����Ʈ�̴ϱ� 1����Ʈ�� ���� �ƽ�ġ�� �޾ƿ� ����
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


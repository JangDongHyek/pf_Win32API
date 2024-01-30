#pragma once
class Core
{
public:
	Core();
	~Core();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc = {};
	POINT _pos = { 200,200 };
};


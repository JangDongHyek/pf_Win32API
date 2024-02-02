#pragma once
#include "ResourceBase.h"
class Texture : public ResourceBase
{
public:
	Texture();
	virtual ~Texture();

public:
	Texture* LoadBmp(HWND hwnd, const std::wstring& path);
	HDC GetDC();

	void SetSize(PosInt size) { _size = size; }
	PosInt GetSize() { return _size; }

	void SetTransparent(uint32 transparent) { _transparent = transparent; }
	int32 GetTransparent() { return _transparent; }

private:
	HDC _hdc = {};
	HBITMAP _bitmap = {};
	PosInt _size = {};
	int32 _transparent = RGB(255, 0, 255);
};


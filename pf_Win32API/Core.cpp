#include "pch.h"
#include "Core.h"

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


}

void Core::Update()
{

}

void Core::Render()
{
	::Rectangle(_hdc, 200, 200, 400, 400);
}

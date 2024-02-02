#include "pch.h"
#include "ResourceMgr.h"
#include "Texture.h"
#include "Sprite.h"

ResourceMgr::~ResourceMgr()
{
}

void ResourceMgr::Init(HWND hwnd, fs::path resourcePath)
{
	_hwnd = hwnd;
	_resourcePath = resourcePath;
}

void ResourceMgr::Clear()
{
	for (auto& item : _textures)
	{
		if (item.second)
		{
			delete item.second;
			item.second = nullptr;
		}
	}

	_textures.clear();
}

Texture* ResourceMgr::LoadTexture(const std::wstring& key, const std::wstring& path, uint32 transparent)
{
	if (_textures.find(key) != _textures.end())
		return _textures[key];

	fs::path fullPath = _resourcePath / path;

	Texture* texture = new Texture();
	texture->LoadBmp(_hwnd, fullPath.c_str());
	texture->SetTransparent(transparent);
	_textures[key] = texture;

	return texture;
}

Sprite* ResourceMgr::CreateSprite(const std::wstring& key, Texture* texture, int32 x, int32 y, int32 cx, int32 cy)
{
	if (_sprites.find(key) != _sprites.end())
		return _sprites[key];

	if (cx == 0)
		cx = texture->GetSize().x;
	if (cy == 0)
		cy = texture->GetSize().y;

	Sprite* sprite = new Sprite(texture, x, y, cx, cy);
	_sprites[key] = sprite;

	return sprite;
}

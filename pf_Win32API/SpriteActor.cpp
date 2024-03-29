#include "pch.h"
#include "SpriteActor.h"
#include "Sprite.h"

SpriteActor::SpriteActor()
{
}

SpriteActor::~SpriteActor()
{
}

void SpriteActor::BeginPlay()
{
	Super::BiginPlay();
}

void SpriteActor::Tick()
{
	Super::Tick();
}

void SpriteActor::Render(HDC hdc)
{
	Super::Render(hdc);

	if (_sprite == nullptr)
		return;

	PosInt size = _sprite->GetSize();

	/*::TransparentBlt(hdc,
	(int32)_pos.x - size.x / 2 - ((int32)cameraPos.x - GWinSizeX / 2),
	(int32)_pos.y - size.y / 2 - ((int32)cameraPos.y - GWinSizeY / 2),
	size.x,
	size.y,
	_sprite->GetDC(),
	_sprite->GetPos().x,
	_sprite->GetPos().y,
	_sprite->GetSize().x,
	_sprite->GetSize().y,
	_sprite->GetTransparent());*/

	::BitBlt(hdc,
		(int32)_pos.x - size.x / 2,
		(int32)_pos.y - size.y / 2,
		size.x,
		size.y,
		_sprite->GetDC(),
		_sprite->GetPos().x,
		_sprite->GetPos().y,
		SRCCOPY);
}

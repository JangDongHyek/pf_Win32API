#pragma once
#include "Actor.h"

class Sprite;

class SpriteActor : public Actor
{
	using Super = Actor;

public:
	SpriteActor();
	virtual ~SpriteActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetSprite(Sprite* sprite) { _sprite = sprite; }

protected :
	Sprite* _sprite = nullptr;
};


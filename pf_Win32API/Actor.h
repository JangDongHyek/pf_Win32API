#pragma once
class Actor
{
public:
	Actor();
	virtual ~Actor();

	virtual void BiginPlay();
	virtual void Tick();
	virtual void Render(HDC hdc);

	void SetPos(Pos pos) { _pos = pos; }
	Pos GetPos() { return _pos; }

protected:
	Pos _pos = {0,0};

};


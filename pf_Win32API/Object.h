#pragma once

enum class ObjectType
{
	None,
	Player,
	Projectile
};

enum class MoveDir
{
	Left,
	Right
};

class Object
{
public:
	Object(ObjectType type);
	virtual ~Object();

	virtual void Init() abstract;
	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

public:
	ObjectType GetObjectType() { return _type; }

	Pos GetPos() { return _pos; }
	void SetPos(Pos pos) { _pos = pos; }


protected:
	ObjectType	_type = ObjectType::None;
	MoveDir		_dir = MoveDir::Right;
	Pos			_pos = {};
};


#include "pch.h"
#include "Player.h"
#include "InputMgr.h"
#include "TimeMgr.h"

Player::Player() : Object(ObjectType::Player)
{
}

Player::~Player()
{
}

void Player::Init()
{
	_pos.x = 0;
	_pos.y = 0;

}

void Player::Update()
{
	float deltaTime = GET_SINGLE(TimeMgr)->GetDeltaTime();

	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::A))
		_pos.x -= 100 * deltaTime;

	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::D))
		_pos.x += 100 * deltaTime;

	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::W))
		_pos.y -= 100 * deltaTime;

	if (GET_SINGLE(InputMgr)->GetButtonPress(KeyType::S))
		_pos.y += 100 * deltaTime;
}

void Player::Render(HDC hdc)
{
	::Rectangle(hdc,
		_pos.x - 50, _pos.y - 50,
		_pos.x + 50, _pos.y + 50);
}

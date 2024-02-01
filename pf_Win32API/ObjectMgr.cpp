#include "pch.h"
#include "ObjectMgr.h"

ObjectMgr::~ObjectMgr()
{
	Clear();
}

void ObjectMgr::Add(Object* object)
{
	if (object == nullptr)
		return;

	auto findIt = std::find(_objects.begin(), _objects.end(), object);
	if (findIt != _objects.end())
		return;

	_objects.push_back(object);
}

void ObjectMgr::Remove(Object* object)
{
	if (object == nullptr)
		return;

	auto it = std::remove(_objects.begin(), _objects.end(), object);
	_objects.erase(it, _objects.end());

	delete object;
}

void ObjectMgr::Clear()
{
	std::for_each(_objects.begin(), _objects.end(), [=](Object* obj) {delete obj; });
	_objects.clear();
}

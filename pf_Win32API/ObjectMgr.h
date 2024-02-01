#pragma once
class Object;

class ObjectMgr
{
	DECLARE_SINGLE(ObjectMgr);

public:
	~ObjectMgr();

	void Add(Object* object);
	void Remove(Object* object);
	void Clear();

	const std::vector<Object*>& GetObjects() { return _objects; }

	// Object들마다 생성을하면 관리가어려워 Mgr 내 템플릿으로 하나로 관리
	template<typename T>
	T* CreatObject()
	{
		
		static_assert(std::is_convertible_v<T*, Object*>);

		T* object = new T();
		object->Init();

		return object;
	}

private:
	std::vector<Object*> _objects;
};


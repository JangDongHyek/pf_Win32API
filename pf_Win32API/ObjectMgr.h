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

	// Object�鸶�� �������ϸ� ����������� Mgr �� ���ø����� �ϳ��� ����
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


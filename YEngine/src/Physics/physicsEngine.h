#pragma once

#include "VectorMath.h"
#include "intersectData.h"
#include "physicsObject.h"
#include <vector>

// �������浥��ʵ��
// ʹ�� Meyers ����ģ��
class PhysicsEngine
{
public:
	static PhysicsEngine& Get()
	{
		static PhysicsEngine instance;
		return instance;
	}

	void AddObject(PhysicsObject& object);

	// ����ģ�⣬��һ������������Ϸ�ڲ���ɵģ�Ŀǰ��ʱû���õ�
	void Simulate(float delta);

	// ��ײ����
	// ��δ���ƣ�Ŀǰֻ�����˰�Χ����ƽ�����ײ
	bool HandleCollisions();

	//TODO: Temporary Getters
	inline PhysicsObject& YGetObject(unsigned int index)
	{
		return m_objects[index];
	}
	inline unsigned int GetNumObjects()
	{
		return (unsigned int)m_objects.size();
	}
private:
	// �����������棬��Ҫ��m_objects����ע��
	std::vector<PhysicsObject> m_objects;

	PhysicsEngine() = default;
	~PhysicsEngine() = default;
	PhysicsEngine(const PhysicsEngine&) = delete;
	PhysicsEngine(PhysicsEngine&&) = delete;
	PhysicsEngine& operator=(const PhysicsEngine&) = delete;
	PhysicsEngine& operator=(PhysicsEngine&&) = delete;
};
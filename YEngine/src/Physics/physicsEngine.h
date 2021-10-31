#pragma once

#include "VectorMath.h"
#include "intersectData.h"
#include "physicsObject.h"
#include <vector>

// 物理引擎单例实现
// 使用 Meyers 单例模型
class PhysicsEngine
{
public:
	static PhysicsEngine& Get()
	{
		static PhysicsEngine instance;
		return instance;
	}

	void AddObject(PhysicsObject& object);

	// 物理模拟，这一步我们是在游戏内部完成的，目前暂时没有用到
	void Simulate(float delta);

	// 碰撞处理
	// 还未完善，目前只处理了包围球与平面的碰撞
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
	// 加入物理引擎，需要向m_objects数组注册
	std::vector<PhysicsObject> m_objects;

	PhysicsEngine() = default;
	~PhysicsEngine() = default;
	PhysicsEngine(const PhysicsEngine&) = delete;
	PhysicsEngine(PhysicsEngine&&) = delete;
	PhysicsEngine& operator=(const PhysicsEngine&) = delete;
	PhysicsEngine& operator=(PhysicsEngine&&) = delete;
};
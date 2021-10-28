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

	void AddObject(const PhysicsObject& object);

	/**
	 * Simulates the physics world for a certain period of time. Does not take
	 * object interaction into accounter; if two objects run into each other,
	 * they will pass through each other.
	 *
	 * If object interaction is desired, collision detection and response must
	 * be performed after this.
	 *
	 * @param delta How much time to simulate.
	 */
	void Simulate(float delta);

	/**
	 * Finds all objects that have collided since the last step and updates
	 * them to adjust for the collision.
	 */
	void HandleCollisions();

	//TODO: Temporary Getters
	inline const PhysicsObject& GetObject(unsigned int index) const
	{
		return m_objects[index];
	}
	inline unsigned int GetNumObjects() const
	{
		return (unsigned int)m_objects.size();
	}
private:
	/** All the objects being simulated by the PhysicsEngine. */
	std::vector<PhysicsObject> m_objects;

	PhysicsEngine() = default;
	~PhysicsEngine() = default;
	PhysicsEngine(const PhysicsEngine&) = delete;
	PhysicsEngine(PhysicsEngine&&) = delete;
	PhysicsEngine& operator=(const PhysicsEngine&) = delete;
	PhysicsEngine& operator=(PhysicsEngine&&) = delete;
};
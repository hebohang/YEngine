#pragma once

#include "collider.h"

class PhysicsObject
{
public:
	PhysicsObject(Collider* collider, Math::Vector3& velocity) :
		m_position(collider->GetCenter()),
		m_oldPosition(collider->GetCenter()),
		m_velocity(velocity),
		m_collider(collider) {}

	PhysicsObject(const PhysicsObject& other);
	void operator=(PhysicsObject other);
	virtual ~PhysicsObject();

	void Integrate(float delta);

	inline const Math::Vector3& GetPosition() const { return m_position; }
	inline const Math::Vector3& GetVelocity() const { return m_velocity; }

	inline void SetPosition(const Math::Vector3& position) { m_position = position; }
	inline void SetVelocity(const Math::Vector3& velocity) { m_velocity = velocity; }

	inline Collider& GetCollider()
	{
		return *m_collider;
	}

private:
	// 暂时都没有用到
	Math::Vector3 m_position;
	Math::Vector3 m_oldPosition;
	Math::Vector3 m_velocity;
	
	Collider* m_collider;
};
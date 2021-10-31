#include "pch.h"
#include "physicsEngine.h"
#include "YBoundingSphere.h"
#include "collider.h"
#include <iostream>

void PhysicsEngine::AddObject(PhysicsObject& object)
{
	m_objects.push_back(object);
}

void PhysicsEngine::Simulate(float delta)
{
	for (unsigned int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].Integrate(delta);
	}
}

bool PhysicsEngine::HandleCollisions()
{
	// 暴力双重循环去处理碰撞
	for (unsigned int i = 0; i < m_objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < m_objects.size(); j++)
		{
			if (m_objects[i].GetCollider().GetType() == Collider::TYPE_PLANE)
				continue;
			IntersectData intersectData =
				m_objects[i].GetCollider().Intersect(
					&m_objects[j].GetCollider());

			if (intersectData.GetDoesIntersect())
			{
				return true;
			}
		}
	}

	return false;
}
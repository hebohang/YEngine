#include "pch.h"
#include "physicsEngine.h"
#include "boundingSphere.h"

void PhysicsEngine::AddObject(const PhysicsObject& object)
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

void PhysicsEngine::HandleCollisions()
{
	// 暴力双重循环去处理碰撞
	for (unsigned int i = 0; i < m_objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < m_objects.size(); j++)
		{
			IntersectData intersectData =
				m_objects[i].GetCollider().Intersect(
					m_objects[j].GetCollider());

			if (intersectData.GetDoesIntersect())
			{
				Math::Vector3 direction = Math::Vector3(DirectX::XMVector3Normalize(
					intersectData.GetDirection().operator DirectX::XMVECTOR()
				));
				Math::Vector3 otherDirection = Math::Vector3(DirectX::XMVector3Reflect(
					direction.operator DirectX::XMVECTOR(),
					DirectX::XMVector3Normalize(m_objects[i].GetVelocity().operator DirectX::XMVECTOR())
				));
				m_objects[i].SetVelocity(Math::Vector3(DirectX::XMVector3Reflect(
					m_objects[i].GetVelocity().operator DirectX::XMVECTOR(),
					otherDirection.operator DirectX::XMVECTOR()
				)));
				m_objects[j].SetVelocity(Math::Vector3(DirectX::XMVector3Reflect(
					m_objects[j].GetVelocity().operator DirectX::XMVECTOR(),
					direction.operator DirectX::XMVECTOR()
				)));
			}
		}
	}
}
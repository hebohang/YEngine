#pragma once

#include "VectorMath.h"
#include "intersectData.h"
#include "YBoundingSphere.h"
#include "collider.h"

class YPlane : public Collider
{
public:
	YPlane(const Math::Vector3& normal, float distance) :
		Collider(Collider::TYPE_PLANE),
		m_normal(normal),
		m_distance(distance) {}

	YPlane Normalized();

	inline Math::Vector3& GetNormal() { return m_normal; }
	inline float GetDistance() const { return m_distance; }

private:
	// ƽ�淨��
	Math::Vector3 m_normal;
	// ��ԭ���ط��ߵ���ƽ��ľ��룬������
	const float    m_distance;
};



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
	// 平面法线
	Math::Vector3 m_normal;
	// 从原点沿法线到达平面的距离，带符号
	const float    m_distance;
};



#pragma once

#include "VectorMath.h"
#include "intersectData.h"

class BoundingSphere
{
public:
	BoundingSphere(const Math::Vector3& center, float radius) :
		m_center(center),
		m_radius(radius) {}

	IntersectData IntersectBoundingSphere(const BoundingSphere& other);

	virtual void Transform(const Math::Vector3& translation);
	virtual Math::Vector3 GetCenter() const { return m_center; }

	inline float GetRadius()           const { return m_radius; }
private:
	Math::Vector3 m_center;
	const float    m_radius;
};
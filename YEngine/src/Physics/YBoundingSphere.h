#pragma once

#include "collider.h"
#include "intersectData.h"

class YPlane;

class YBoundingSphere : public Collider
{
public:
	YBoundingSphere(const Math::Vector3& center, float radius) :
		Collider(Collider::TYPE_SPHERE),
		m_center(center),
		m_radius(radius) {}

	void SetCenter(Math::Vector3 in_center)
	{
		m_center = in_center;
	}

	IntersectData IntersectYBoundingSphere(YBoundingSphere* other);
	IntersectData IntersectYPlane(YPlane* other);

	IntersectData Intersect(Collider* other) override;

	virtual void Transform(const Math::Vector3& translation);
	virtual Math::Vector3 GetCenter() const { return m_center; }

	inline float GetRadius()           const { return m_radius; }
private:
	Math::Vector3 m_center;
	const float    m_radius;
};
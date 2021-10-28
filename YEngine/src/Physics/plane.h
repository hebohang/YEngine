#pragma once

#include "VectorMath.h"
#include "intersectData.h"
#include "boundingSphere.h"

class Plane
{
public:
	/**
	 * Creates a Plane in a usable state.
	 *
	 * @param normal   The "up" direction from the plane's surface.
	 * @param distance The distance to the plane from the world origin
	 *                   along the normal
	 */
	Plane(const Math::Vector3& normal, float distance) :
		m_normal(normal),
		m_distance(distance) {}

	/**
	 * Creates an equivalent plane with a normal at unit length and distance
	 * adjusted accordingly.
	 */
	Plane Normalized();

	/**
	 * Computes information about if this Plane intersects a Sphere.
	 *
	 * @param other The Sphere that's being tested for intersection with this
	 *                Plane.
	 */
	IntersectData IntersectSphere(const BoundingSphere& other) const;

	inline Math::Vector3& GetNormal() { return m_normal; }
	inline float GetDistance() const { return m_distance; }

private:
	// 平面法线
	Math::Vector3 m_normal;
	// 从原点沿法线到达平面的距离，带符号
	const float    m_distance;
};



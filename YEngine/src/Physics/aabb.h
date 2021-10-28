#pragma once

#include "VectorMath.h"
#include "intersectData.h"

class AABB
{
public:
	/**
	 * Creates an AABB in a usable state.
	 *
	 * @param minExtents The corner of the AABB with the smallest coordinates.
	 * @param maxExtents The corner of the AABB with the largest coordinates.
	 */
	AABB(const Math::Vector3& minExtents, const Math::Vector3& maxExtents) :
		m_minExtents(minExtents),
		m_maxExtents(maxExtents) {}

	/**
	 * Computes information about if this AABB intersects another AABB.
	 *
	 * @param other The AABB that's being tested for intersection with this
	 *                AABB.
	 */
	IntersectData IntersectAABB(const AABB& other) const;

	/** Basic getter for the min extents */
	inline const Math::Vector3& GetMinExtents() const { return m_minExtents; }
	/** Basic getter for the max extents */
	inline const Math::Vector3& GetMaxExtents() const { return m_maxExtents; }

private:
	// AABB盒的左下角坐标
	const Math::Vector3 m_minExtents;
	// AABB盒的右上角坐标
	const Math::Vector3 m_maxExtents;
};
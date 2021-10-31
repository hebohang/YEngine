#pragma once

#include "VectorMath.h"
#include "intersectData.h"
#include "collider.h"

class YAABB : public Collider
{
public:
	YAABB(const Math::Vector3& minExtents, const Math::Vector3& maxExtents) :
		Collider(Collider::TYPE_AABB),
		m_minExtents(minExtents),
		m_maxExtents(maxExtents) {}

	// 还未完全AABB的方法
	IntersectData IntersectAABB(const YAABB& other) const;

	inline const Math::Vector3& GetMinExtents() const { return m_minExtents; }

	inline const Math::Vector3& GetMaxExtents() const { return m_maxExtents; }

private:
	// YAABB盒的左下角坐标
	const Math::Vector3 m_minExtents;
	// YAABB盒的右上角坐标
	const Math::Vector3 m_maxExtents;
};
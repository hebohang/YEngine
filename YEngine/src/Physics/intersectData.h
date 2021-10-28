#pragma once

#include "VectorMath.h"

// 通过相交的信息在后续判断
// 目前仅存储方向信息（两个碰撞体中心连线）
class IntersectData
{
public:
	/**
	 * Creates Intersect Data in a usable state.
	 *
	 * @param doesIntersect Whether or not the objects are intersecting.
	 * @param direction     The collision normal, with length set to distance.
	 */
	IntersectData(const bool doesIntersect, const Math::Vector3& direction) :
		m_doesIntersect(doesIntersect),
		m_direction(direction) {}

	/** Basic getter for m_doesIntersect */
	inline bool GetDoesIntersect() const { return m_doesIntersect; }
	/** Basic getter for m_distance */
	inline float GetDistance() { return m_direction.Length().GetX().operator float(); }

	inline Math::Vector3 GetDirection() const { return m_direction; }
private:
	// 是否相交判定
	const bool  m_doesIntersect;
	// 碰撞的方向，长度为distance
	Math::Vector3 m_direction;
};
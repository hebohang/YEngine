#pragma once

#include "VectorMath.h"

// 通过相交的信息在后续判断
// 目前仅存储方向信息（两个碰撞体中心连线）
class IntersectData
{
public:
	IntersectData(bool doesIntersect, Math::Vector3& direction) :
		m_doesIntersect(doesIntersect),
		m_direction(direction) {}

	inline bool GetDoesIntersect() const { return m_doesIntersect; }

	inline float GetDistance() { return m_direction.Length().GetX().operator float(); }

	inline Math::Vector3 GetDirection() const { return m_direction; }
private:
	// 是否相交判定
	const bool  m_doesIntersect;
	// 碰撞的方向，长度为distance
	Math::Vector3 m_direction;
};
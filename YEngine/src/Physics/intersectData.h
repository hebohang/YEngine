#pragma once

#include "VectorMath.h"

// ͨ���ཻ����Ϣ�ں����ж�
// Ŀǰ���洢������Ϣ��������ײ���������ߣ�
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
	// �Ƿ��ཻ�ж�
	const bool  m_doesIntersect;
	// ��ײ�ķ��򣬳���Ϊdistance
	Math::Vector3 m_direction;
};
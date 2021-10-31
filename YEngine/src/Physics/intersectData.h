#pragma once

#include "VectorMath.h"

// ͨ���ཻ����Ϣ�ں����ж�
// Ŀǰ���洢������Ϣ��������ײ���������ߣ�
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
	// �Ƿ��ཻ�ж�
	const bool  m_doesIntersect;
	// ��ײ�ķ��򣬳���Ϊdistance
	Math::Vector3 m_direction;
};
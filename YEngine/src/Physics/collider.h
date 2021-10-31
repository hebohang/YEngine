#pragma once

#include "VectorMath.h"
#include "intersectData.h"

class Collider
{
public:
	enum
	{
		TYPE_SPHERE,
		TYPE_AABB,
		TYPE_PLANE
	};

	Collider(int type) :
		m_type(type) {}

	// �����ཻ����Ϣ��Ŀǰֻ����İ�Χ��
	virtual IntersectData Intersect(Collider* other)
	{
		return IntersectData(false, Math::Vector3(0.0f, 0.0f, 0.0f));
	}

	virtual void Transform(Math::Vector3& translation) {}

	virtual Math::Vector3 GetCenter() { return Math::Vector3(0, 0, 0); }

	inline int GetType() { return m_type; }
private:
	int m_type;
};
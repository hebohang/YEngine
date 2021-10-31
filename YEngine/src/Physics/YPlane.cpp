#include "pch.h"
#include "YPlane.h"

YPlane YPlane::Normalized()
{
	float magnitude = m_normal.Length().GetX().operator float();

	return YPlane(m_normal / magnitude, m_distance / magnitude);
}


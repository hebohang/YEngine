#include "pch.h"
#include "boundingSphere.h"

IntersectData BoundingSphere::IntersectBoundingSphere(const BoundingSphere& other)
{
	Math::Vector3 radiusDistance = m_radius + other.GetRadius();
	Math::Vector3 direction = (other.GetCenter() - m_center);
	Math::Vector3 centerDistance = direction.Length();
	direction /= centerDistance;

	Math::Vector3 distance = centerDistance - radiusDistance;

	return IntersectData((centerDistance.GetX().operator float() < radiusDistance.GetX().operator float()), distance * direction);
}

void BoundingSphere::Transform(const Math::Vector3& translation)
{
	m_center += translation;
}
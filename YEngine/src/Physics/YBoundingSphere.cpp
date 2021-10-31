#include "pch.h"
#include "YBoundingSphere.h"
#include "YPlane.h"

IntersectData YBoundingSphere::IntersectYBoundingSphere(YBoundingSphere* other)
{
	Math::Vector3 radiusDistance = m_radius + other->GetRadius();
	Math::Vector3 direction = (other->GetCenter() - m_center);
	Math::Vector3 centerDistance = direction.Length();
	direction /= centerDistance;

	Math::Vector3 distance = centerDistance - radiusDistance;

	return IntersectData((centerDistance.GetX().operator float() < radiusDistance.GetX().operator float()), distance * direction);
}

IntersectData YBoundingSphere::IntersectYPlane(YPlane* other)
{
	// 先归一化处理，求出球心向量到平面法向量的投影
	other->Normalized();
	float distanceFromSphereCenter =
		(float)fabs(DirectX::XMVector3Dot(other->GetNormal().operator DirectX::XMVECTOR(), m_center.operator DirectX::XMVECTOR()).m128_f32[0]);

	// 平面距离减去投影长度，该值与球半径判断大小关系即可判断是否相交
	float distanceFromSphere = other->GetDistance() - distanceFromSphereCenter;

	return IntersectData(fabs(distanceFromSphere) < m_radius, other->GetNormal() * distanceFromSphere);
}

IntersectData YBoundingSphere::Intersect(Collider* other)
{
	if (other->GetType() == TYPE_SPHERE)
		return IntersectYBoundingSphere(static_cast<YBoundingSphere*>(other));
	else if (other->GetType() == TYPE_PLANE)
		return IntersectYPlane(static_cast<YPlane*>(other));
}

void YBoundingSphere::Transform(const Math::Vector3& translation)
{
	m_center += translation;
}
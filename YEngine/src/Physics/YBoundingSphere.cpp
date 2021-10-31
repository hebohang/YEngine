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
	// �ȹ�һ�������������������ƽ�淨������ͶӰ
	other->Normalized();
	float distanceFromSphereCenter =
		(float)fabs(DirectX::XMVector3Dot(other->GetNormal().operator DirectX::XMVECTOR(), m_center.operator DirectX::XMVECTOR()).m128_f32[0]);

	// ƽ������ȥͶӰ���ȣ���ֵ����뾶�жϴ�С��ϵ�����ж��Ƿ��ཻ
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
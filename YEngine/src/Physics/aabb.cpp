#include "pch.h"
#include "aabb.h"

IntersectData AABB::IntersectAABB(const AABB& other) const
{
	// �����Ͼ����ڸ��������ж���û���ཻ
	// ͨ��������½Ǻ��ҵ����Ͻǡ��Լ��ҵ����½Ǻ�������Ͻ�����ȥ�ж�
	Math::Vector3 distances1 = other.GetMinExtents() - m_maxExtents;
	Math::Vector3 distances2 = m_minExtents - other.GetMaxExtents();

	// ����ÿ�������ϵ����ֵ�������С��0���ʾ�϶��ཻ��
	Math::Vector3 distances = Math::Vector3(Math::XMVectorMax(distances1.operator DirectX::XMVECTOR(), distances2.operator DirectX::XMVECTOR()));

	float maxDistance = distances.Max();

	//If there is any distance between the two AABB's, then max distance will
	//be greather than or equal to 0. If there is distance between the two
	//AABBs, then they aren't intersecting.
	//
	//Therefore, if the AABBs are intersecting, then the distance between them
	//must be less than zero.

	//TODO: This might actually need to return the minDistance if they are 
	//intersecting.
	return IntersectData(maxDistance < 0, distances);
}
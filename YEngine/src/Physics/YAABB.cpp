#include "pch.h"
#include "YAABB.h"

IntersectData YAABB::IntersectAABB(const YAABB& other) const
{
	// �����Ͼ����ڸ��������ж���û���ཻ
	// ͨ��������½Ǻ��ҵ����Ͻǡ��Լ��ҵ����½Ǻ�������Ͻ�����ȥ�ж�
	Math::Vector3 distances1 = other.GetMinExtents() - m_maxExtents;
	Math::Vector3 distances2 = m_minExtents - other.GetMaxExtents();

	// ����ÿ�������ϵ����ֵ�������С��0���ʾ�϶��ཻ��
	Math::Vector3 distances = Math::Vector3(Math::XMVectorMax(distances1.operator DirectX::XMVECTOR(), distances2.operator DirectX::XMVECTOR()));

	float maxDistance = distances.Max();

	// ��δ��ȫAABB�ķ���
	return IntersectData(maxDistance < 0, distances);
}
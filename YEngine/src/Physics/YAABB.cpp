#include "pch.h"
#include "YAABB.h"

IntersectData YAABB::IntersectAABB(const YAABB& other) const
{
	// 本质上就是在各个轴上判断有没有相交
	// 通过你的左下角和我的右上角、以及我的左下角和你的右上角做差去判断
	Math::Vector3 distances1 = other.GetMinExtents() - m_maxExtents;
	Math::Vector3 distances2 = m_minExtents - other.GetMaxExtents();

	// 返回每个分量上的最大值，如果都小于0则表示肯定相交了
	Math::Vector3 distances = Math::Vector3(Math::XMVectorMax(distances1.operator DirectX::XMVECTOR(), distances2.operator DirectX::XMVECTOR()));

	float maxDistance = distances.Max();

	// 还未完全AABB的方法
	return IntersectData(maxDistance < 0, distances);
}
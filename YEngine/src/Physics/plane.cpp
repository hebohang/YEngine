#include "pch.h"
#include "plane.h"

Plane Plane::Normalized()
{
	float magnitude = m_normal.Length().GetX().operator float();

	//Dividing the normal by it's length performs vector normalization.
	//Distance however, must also be divided by the normal's length in
	//order to create an equivalent plane.
	return Plane(m_normal / magnitude, m_distance / magnitude);
}

IntersectData Plane::IntersectSphere(const BoundingSphere& other) const
{
	//Calculating the dot product between the Plane's normal and the Sphere's 
	//center gets how far the sphere's center is along the Plane's normal.
	//
	//Adding the distance adjusts this value based on how far the Plane itself
	//is along the normal.
	//
	//The end result of this is how far the Sphere's center is from the Plane.
	//The absolute value is taken so that this result is always positive.
	float distanceFromSphereCenter =
		(float)fabs(DirectX::XMVector3Dot(m_normal.operator DirectX::XMVECTOR(), other.GetCenter().operator DirectX::XMVECTOR()).m128_f32[0]);

	//As long as the distanceFromSphereCenter is valid and positive, then
	//the distance from the sphere can be calculated simply by subtracting
	//it's radius.
	float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();

	//The only time the plane can be intersecting the sphere is if the sphere
	//has less than 0 distance from the plane. Otherwise, if there is distance
	//between the plane and sphere, then there must be a gap between the
	//plane and sphere, and they cannot be intersecting.
	return IntersectData(distanceFromSphere < 0, m_normal* distanceFromSphere);
}

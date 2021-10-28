#include "pch.h"
#include "collider.h"
#include "boundingSphere.h"

IntersectData Collider::Intersect(const Collider& other) const
{
	assert(m_type == TYPE_SPHERE && other.GetType() == TYPE_SPHERE);
	BoundingSphere* self = (BoundingSphere*)this;
	return self->IntersectBoundingSphere((BoundingSphere&)other);
}
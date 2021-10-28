#pragma once

#include "VectorMath.h"
#include "intersectData.h"

class Collider
{
public:
	/**
	 * This enumeration stores all the types of colliders that can be used.
	 */
	enum
	{
		TYPE_SPHERE,
		TYPE_AABB,
		TYPE_PLANE
	};

	/**
	 * Creates a Collider in a usable state.
	 *
	 * @param type The type of collider this represents.
	 */
	Collider(int type) :
		m_type(type) {}

	// 计算相交的信息，目前只处理的包围球
	IntersectData Intersect(const Collider& other) const;

	/**
	 * Moves the entire collider by translation distance. Should be overriden
	 * by subclasses.
	 *
	 * @param translation Distance to move the collider
	 */
	virtual void Transform(const Math::Vector3& translation) {}
	/**
	 * Returns the center position of the collider. Should be overriden by
	 * subclasses.
	 */
	virtual Math::Vector3 GetCenter() const { return Math::Vector3(0, 0, 0); }

	/** Basic getter */
	inline int GetType() const { return m_type; }
private:
	/**
	 * What type of collider this is. Should be set to some value from the
	 * TYPE enum. This value determines what sort of intersect checks are used
	 * and other details about the collider; should only be set by an appropriate
	 * subclass or strange behaviour may result!
	 */
	int m_type;
};
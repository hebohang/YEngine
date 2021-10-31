#include "pch.h"
#include "physicsObject.h"

PhysicsObject::PhysicsObject(const PhysicsObject& other) :
	m_position(other.m_position),
	m_oldPosition(other.m_oldPosition),
	m_velocity(other.m_velocity),
	m_collider(other.m_collider) {}

void PhysicsObject::operator=(PhysicsObject other)
{
	//Implemented using the copy/swap idiom.
	char* temp[sizeof(PhysicsObject) / sizeof(char)];
	memcpy(temp, this, sizeof(PhysicsObject));
	memcpy(this, &other, sizeof(PhysicsObject));
	memcpy(&other, temp, sizeof(PhysicsObject));
}

PhysicsObject::~PhysicsObject()
{
	// if (m_collider) delete m_collider;
}


void PhysicsObject::Integrate(float delta)
{
	m_position += m_velocity * delta;
}

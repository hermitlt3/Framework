#ifndef SPATIALPARTITION_H
#define SPATIALPARTITION_H

#include "Vector3.h"
#include "Transform\CTransform.h"

class EntityBase;

class Octree
{
public:
	Octree();

	Octree(	const float& minX, const float& maxX,
			const float& minY, const float& maxY,
			const float& minZ, const float& maxZ);

	Octree(	const Vector3& min, const Vector3& max);
	~Octree();

	// Get the parent node
	inline Octree* GetParent() { return parent; };
	// Get the smallest node from position
	Octree* GetNodeFromPos(const Vector3& pos);

	// Add entity to octree node
	void Add(EntityBase* entity);
	// Remove entity from octree node
	EntityBase* Remove(EntityBase* entity);

protected:
	// Mainly scale and translate of the octree nodes
	CTransform transform;
	// Child octree nodes
	Octree* child[8];
	// Parent octree node
	Octree* parent;

private:
	const float MIN_SCALE = 1.f;
	int depth;
};

#endif
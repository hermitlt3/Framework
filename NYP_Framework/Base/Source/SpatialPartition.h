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
	// Set the parent node
	bool SetParent(const Octree* _parent);
	
	// Get the smallest node from position
	Octree* GetNodeFromPos(const Vector3& pos);

	// Add entity to octree node
	void Add(EntityBase* entity);
	// Remove entity from octree node
	EntityBase* Remove(EntityBase* entity);
	// Divides the octree into eight child nodes
	bool DivideOctree();

protected:
	// Mainly scale and translate of the octree nodes
	CTransform transform;
	// Child octree nodes
	Octree* child[8];
	// Parent octree node
	Octree* parent;

private:
	// Limit for octree division
	const float MAX_DEPTH = 4;
	// Ratio for each node to scale to overlap
	float PERCENT_SCALE;
	// Counter for how many times tree divided
	int depth;
};

#endif
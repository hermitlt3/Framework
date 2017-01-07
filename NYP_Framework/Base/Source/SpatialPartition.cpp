#include "SpatialPartition.h"

Octree::Octree() :
PERCENT_SCALE(100.f)
{
	for (int i = 0; i < 8; ++i) {
		child[i] = nullptr;
	}
}

Octree::Octree(	const float& minX, const float& maxX,
				const float& minY, const float& maxY,
				const float& minZ, const float& maxZ) :
PERCENT_SCALE(100.f)
{
	for (int i = 0; i < 8; ++i) {
		child[i] = nullptr;
	}
}

Octree::Octree(const Vector3& min, const Vector3& max) :
PERCENT_SCALE(100.f)
{
	for (int i = 0; i < 8; ++i) {
		child[i] = nullptr;
	}
}

Octree* Octree::GetNodeFromPos(const Vector3& pos)
{
	for (int i = 0; i < 8; ++i) {
		if (transform.GetLocalTranslate().x - transform.GetScale().x < pos.x &&
			transform.GetLocalTranslate().x + transform.GetScale().x > pos.x &&
			transform.GetLocalTranslate().y - transform.GetScale().x < pos.y &&
			transform.GetLocalTranslate().y + transform.GetScale().x > pos.y &&
			transform.GetLocalTranslate().z - transform.GetScale().x < pos.z &&
			transform.GetLocalTranslate().z + transform.GetScale().x > pos.z)
		{
			if (child[i]) {
				child[i]->GetNodeFromPos(pos);
			}
			else 
				return this;
		}
	}
	return nullptr;
}

void Octree::Add(EntityBase* entity)
{

}

EntityBase* Octree::Remove(EntityBase* entity)
{
	return nullptr;
}

bool Octree::DivideOctree()
{
	return false;
}
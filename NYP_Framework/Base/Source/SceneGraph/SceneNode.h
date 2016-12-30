#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "EntityBase.h"
#include <list>
using std::list;

class Mesh;
class SceneNode : public EntityBase
{
public:
	SceneNode();
	SceneNode(Mesh* _mesh);
	virtual ~SceneNode();

	virtual void Update(double _dt);
	virtual void Render();
	virtual void RenderUI() {};

	// Check if this entity has a collider class parent
	virtual bool HasCollider(void) const { return false; };
	// Set the flag to indicate if this entity has a collider class parent
	virtual void SetCollider(const bool _value) {};

	inline int GetID() {
		return ID;
	};
	inline void SetID(const int& _ID) {
		ID = _ID;
	};
	inline Mesh* GetMesh() {
		return nodeMesh;
	}
	inline void SetMesh(Mesh* _mesh) {
		nodeMesh = _mesh;
	}
	bool DetachParent();
	bool DetachChild(SceneNode* theChild);
	bool DetachChild(const int& ID);
	bool DetachAllChildren();

	bool AddParent(SceneNode* theParent);
	bool AddChild(SceneNode* theChild);

	bool DeleteParent();
	bool DeleteChild(SceneNode* theChild);
	bool DeleteChild(const int& ID);
	bool DeleteAllChildren();

	SceneNode* GetNode(const int& ID);

protected:
private:
	SceneNode* parentNode;
	list<SceneNode*> childNodes;
	Mesh* nodeMesh;
	int ID;
};

namespace Create
{
	SceneNode* Node(	const std::string& _meshName,
						const Vector3& _position,
						const Vector3& _scale = Vector3(1.0f, 1.0f, 1.0f));
}

#endif
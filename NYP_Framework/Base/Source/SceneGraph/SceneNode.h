#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include "EntityBase.h"
#include <list>
using std::list;

class SceneNode : public EntityBase
{
public:
	SceneNode();
	virtual ~SceneNode();

	virtual void Update(double _dt);
	virtual void Render();
	virtual void RenderUI() = 0;

	// Check if this entity has a collider class parent
	virtual bool HasCollider(void) const = 0;
	// Set the flag to indicate if this entity has a collider class parent
	virtual void SetCollider(const bool _value) = 0;

	inline int GetID() {
		return ID;
	};
	inline void SetID(const int& _ID) {
		ID = _ID;
	};
	bool DetachParent();
	bool DetachChild(SceneNode* theChild);
	bool DetachAllChildren();

	bool AddParent(SceneNode* theParent);
	bool AddChild(SceneNode* theChild);

	bool DeleteParent();
	bool DeleteChild(SceneNode* theChild);
	bool DeleteAllChildren();

protected:
private:
	SceneNode* parentNode;
	list<SceneNode*> childNodes;
	int ID;
};

#endif
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

	int GetID();
	void SetID(const int& _ID);
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
};

#endif
#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include <list>
using std::list;

class SceneNode;
class SceneGraph
{
public:
	SceneGraph();
	~SceneGraph();

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
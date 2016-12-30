#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "SingletonTemplate.h"

class SceneNode;
class EntityBase;
class SceneGraph : public Singleton<SceneGraph>
{
	friend Singleton<SceneGraph>;
public:
	SceneGraph();
	~SceneGraph();

	void Destroy();

	inline SceneNode* GetRoot() {
		return theRoot;
	}

	SceneNode* GetNode(const int& ID);
	SceneNode* GetNode(EntityBase* theEntity);

	bool AddNode(SceneNode* node);
	bool AddNode(EntityBase* theEntity);

	bool DeleteNode(EntityBase* theEntity);
	bool DeleteNode(const int& ID);

protected:
private:
	int IDGenerator;
	SceneNode* theRoot;
};

#endif
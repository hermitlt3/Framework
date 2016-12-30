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

	bool AddNode(SceneNode* node);
	bool DeleteNode(const int& ID);
	bool DetachNode(const int& ID);

	void GenerateID(SceneNode* node);

protected:
private:
	int IDGenerator;
	SceneNode* theRoot;
};

#endif
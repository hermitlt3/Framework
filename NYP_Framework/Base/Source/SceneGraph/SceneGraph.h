#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "SingletonTemplate.h"

class SceneGraph : public Singleton<SceneGraph>
{
	friend Singleton<SceneGraph>;
public:
	SceneGraph();
	~SceneGraph();

protected:
private:
	int IDGenerator;
};

#endif
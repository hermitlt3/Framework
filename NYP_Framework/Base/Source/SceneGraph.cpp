#include "SceneGraph\SceneGraph.h"
#include "SceneGraph\SceneNode.h"

SceneGraph::SceneGraph() :
IDGenerator(0)
{

}

SceneGraph::~SceneGraph()
{

}

void SceneGraph::Destroy()
{
	if (theRoot)
	{
		theRoot->DeleteAllChildren();
		delete theRoot;
	}
	Singleton<SceneGraph>::Destroy();
}
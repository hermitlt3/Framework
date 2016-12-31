#include "SceneGraph.h"
#include "SceneNode.h"

SceneGraph::SceneGraph() :
IDGenerator(0)
{
	theRoot = new SceneNode();
	theRoot->SetID(IDGenerator++);
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

SceneNode* SceneGraph::GetNode(const int& ID)
{
	return theRoot->GetNode(ID);
}

bool SceneGraph::AddNode(SceneNode* node)
{
	GenerateID(node);
	return theRoot->AddChild(node);
}


bool SceneGraph::DeleteNode(const int& ID)
{
	return theRoot->DeleteChild(ID);
}

bool SceneGraph::DetachNode(const int& ID)
{
	return theRoot->DetachChild(ID);
}

void SceneGraph::GenerateID(SceneNode* node)
{
	node->SetID(IDGenerator++);
}
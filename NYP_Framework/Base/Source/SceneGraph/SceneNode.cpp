#include "SceneNode.h"
#include "SceneGraph.h"
#include "GraphicsManager.h"
#include "../EntityManager.h"
#include "MeshBuilder.h"
#include "RenderHelper.h"

SceneNode::SceneNode() :
parentNode(nullptr),
ID(-1)
{
	childNodes.clear();
}

SceneNode::SceneNode(Mesh* _mesh) :
parentNode(nullptr),
ID(-1)
{
	childNodes.clear();
	nodeMesh = _mesh;
}

SceneNode::~SceneNode()
{
	// Iterate through the list of child Nodes
	for (list<SceneNode*>::iterator lt; lt != childNodes.end(); ++lt) {
		// Deallocate memory 
		delete (*lt);
		(*lt) = nullptr;
	}
	// Clear the list
	childNodes.clear();
}

bool SceneNode::DetachParent()
{
	// If no parent node, return false
	if (!parentNode)
		return false;

	// Parent node points to nothing
	parentNode = nullptr;
	return true;
}

bool SceneNode::DetachChild(SceneNode* theChild)
{
	// If no child node, return false
	if (childNodes.empty())
		return false;

	// Iterate through the list
	for (list<SceneNode*>::iterator lt = childNodes.begin(); lt != childNodes.end();) {
		// Find the child ID
		if ((*lt)->GetID() == theChild->GetID()) {
			// Remove it from the list of child nodes
			lt = childNodes.erase(lt);
			return true;
		}
		else
			lt++;
	}
	// If child node is not found
	return false;
}

bool SceneNode::DetachChild(const int& ID)
{
	SceneNode* tempNode = SceneGraph::GetInstance()->GetNode(ID);
	if (tempNode) {
		DetachChild(tempNode);
		return true;
	} return false;
}

bool SceneNode::AddParent(SceneNode* theParent)
{
	// If there is a parent, return false
	if (parentNode)
		return false;

	// Parent node points to the assigned parent
	parentNode = theParent;
	return true;
}

bool SceneNode::AddChild(SceneNode* theChild)
{
	/*for (list<SceneNode*>::iterator lt = childNodes.begin(); lt != childNodes.end(); ++lt) {
		// If theChild already exists as a child Node
		if ((*lt)->GetID() == theChild->GetID()) {
			return false;
		}
	}*/
	// Adds the child into list of child nodes
	childNodes.push_back(theChild);
	theChild->AddParent(this);
	theChild->SetTranslate(GetLocalTranslate().x, GetLocalTranslate().y, GetLocalTranslate().z);
	theChild->SetRotate(GetRotate().y, 0, 1, 0);
	theChild->SetRotate(GetRotate().x, 1, 0, 0);
	theChild->SetRotate(GetRotate().z, 0, 0, 1);
	theChild->SetScale(GetScale().x, GetScale().y, GetScale().z);
	return true;
}

bool SceneNode::DetachAllChildren()
{
	// Clears the list
	childNodes.clear();
	return true;
}

bool SceneNode::DeleteParent()
{
	// If no parent node, return false
	if (!parentNode)
		return false;

	// Delete the allocated memory
	delete parentNode;
	// Pointer points to nothing
	parentNode = nullptr;

	return false;
}

bool SceneNode::DeleteChild(SceneNode* theChild)
{
	// If no child node, return false
	if (childNodes.empty())
		return false;

	// Iterate through the list
	for (list<SceneNode*>::iterator lt = childNodes.begin(); lt != childNodes.end();) {
		// Find the child ID
		if ((*lt)->GetID() == theChild->GetID()) {
			// Deletes the allocated memory
			delete (*lt);
			// Remove it from the list of child nodes
			lt = childNodes.erase(lt);
			return true;
		}
		else
			lt++;
	}
	// If child node is not found
	return false;
}

bool SceneNode::DeleteChild(const int& ID)
{
	SceneNode* tempNode = SceneGraph::GetInstance()->GetNode(ID);
	if (tempNode) {
		DeleteChild(tempNode); 
		return true;
	} return false;
}

bool SceneNode::DeleteAllChildren()
{
	// Iterate through the list of child Nodes
	for (list<SceneNode*>::iterator lt; lt != childNodes.end(); ++lt) {
		// Deallocate memory 
		delete (*lt);
		(*lt) = nullptr;
	}
	return true;
}

// Update the Scene Graph
void SceneNode::Update(double _dt)
{
	// Update the children
	list<SceneNode*>::iterator it;
	for (it = childNodes.begin(); it != childNodes.end(); ++it)
	{
		(*it)->Update(_dt);
	}
}
// Render the Scene Graph
void SceneNode::Render(void)
{
	MS& modelStack = GraphicsManager::GetInstance()->GetModelStack();
	modelStack.PushMatrix();
	modelStack.Translate(GetLocalTranslate().x, GetLocalTranslate().y, GetLocalTranslate().z);
	modelStack.Rotate(GetRotate().y, 0, 1, 0);
	modelStack.Rotate(GetRotate().x, 1, 0, 0);
	modelStack.Rotate(GetRotate().z, 0, 0, 1);
	modelStack.Scale(GetScale().x, GetScale().y, GetScale().z);
	RenderHelper::RenderMesh(nodeMesh);
	modelStack.PopMatrix();
}

SceneNode* SceneNode::GetNode(const int& ID)
{
	if (this->ID == ID) {
		return this;
	}

	for (list<SceneNode*>::iterator lt = childNodes.begin(); lt != childNodes.end(); ++lt) {
		GetNode(ID);
	}
	return nullptr;
}

bool SceneNode::HasParent()
{
	if (parentNode)
		return true;
	return false;
}

SceneNode* Create::Node(const std::string& _meshName,
	const Vector3& _position,
	const Vector3& _scale)
{
	Mesh* modelMesh = MeshBuilder::GetInstance()->GetMesh(_meshName);
	if (modelMesh == nullptr)
		return nullptr;

	SceneNode* result = new SceneNode(modelMesh);
	result->SetCollider(false);
	result->SetTranslate(_position);
	result->SetScale(_scale);
	EntityManager::GetInstance()->AddEntity(result);

	return result;
}

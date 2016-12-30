#include "SceneGraph\SceneNode.h"

SceneNode::SceneNode() :
parentNode(nullptr)
{
	childNodes.clear();
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

bool SceneNode::AddParent(SceneNode* theParent)
{
	// If there is a parent, return false
	if (parentNode)
		return false;

	// Parent node points to the assigned parent
	parentNode = theParent;
}

bool SceneNode::AddChild(SceneNode* theChild)
{
	for (list<SceneNode*>::iterator lt = childNodes.begin(); lt != childNodes.end(); ++lt) {
		// If theChild already exists as a child Node
		if ((*lt)->GetID() == theChild->GetID()) {
			return false;
		}
	}
	// Adds the child into list of child nodes
	childNodes.push_back(theChild);
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
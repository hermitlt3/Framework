#include "SceneGraph\SceneNode.h"

SceneNode::SceneNode()
{

}

SceneNode::~SceneNode()
{

}

int SceneNode::GetID()
{
	return ID;
}

void SceneNode::SetID(const int& _ID)
{
	this->ID = _ID;
}
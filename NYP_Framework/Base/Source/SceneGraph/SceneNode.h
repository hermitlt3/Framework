#ifndef SCENE_NODE_H
#define SCENE_NODE_H

class SceneNode
{
public:
	SceneNode();
	~SceneNode();

	int GetID();
	void SetID(const int& _ID);

protected:

private:
	int ID;
};

#endif
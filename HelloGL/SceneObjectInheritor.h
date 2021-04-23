#pragma once()
#include "SceneObject.h"
#ifndef _SCENEOBJECTINHERITOR_H
#define _SCENEOBJECTINHERITOR_H
class SceneObjectInheritor : public SceneObject
{
public:
	SceneObjectInheritor();
	~SceneObjectInheritor();

	void Draw();
	void Update();
protected:

private:

};

#endif
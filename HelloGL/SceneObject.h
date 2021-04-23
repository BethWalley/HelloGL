#pragma once

#include "Structures.h"
#include "Texture2D.h"

#ifndef _SCENEOBJECT_H
#define _SCENEOBJECT_H
class SceneObject
{
protected:

	Mesh* _mesh;
	Texture2D* _texture;

public:

	SceneObject(Mesh* mesh, Texture2D* texture);
	virtual ~SceneObject();

	virtual void Update();
	virtual void Draw();

};

#endif

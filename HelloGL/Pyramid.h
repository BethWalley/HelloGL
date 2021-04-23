#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

#ifndef _PYRAMID_H
#define _PYRAMID_H
class Pyramid : public SceneObject
{
public:
	Pyramid(Mesh* mesh, float x, float y, float z);

	~Pyramid();

	void Draw();
	void Update();

protected:


private:
	static int numVertices, numColors, numIndeces;

	GLfloat _rotation;

	Vector3 _position;

	Mesh* _mesh;

};

#endif

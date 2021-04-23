#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"
#include "SceneObject.h"

#ifndef CUBE_H
#define CUBE_H

class Cube : public SceneObject
{

public:

	Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z);

	~Cube();

	void Draw();
	void Update();
private:

	static int numVertices, numNormals, numIndeces;

	GLfloat _rotation;

	Vector4 _position;

	Mesh* _mesh;

};

#endif // !CUBE_H

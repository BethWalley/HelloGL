#include "Pyramid.h"
#include <iostream>
#include <fstream>

int Pyramid::numVertices = 0;
int Pyramid::numColors = 0;
int Pyramid::numIndeces = 0;

Pyramid::Pyramid(Mesh* mesh, float x, float y, float z) : SceneObject(mesh, nullptr)
{
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_mesh = mesh;
}

Pyramid::~Pyramid()
{

}

void Pyramid::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Color != nullptr && _mesh->Indeces != nullptr)
	{
		glPushMatrix();
		glTranslatef(_position.x, _position.y, _position.z);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glColorPointer(0, GL_FLOAT, 0, _mesh->Color);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation * 2, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation / 2, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, _mesh->Indeces);


		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_VERTEX_ARRAY);
		glPopMatrix();
	}
}

void Pyramid::Update()
{
	_rotation += rand() % 3;
}

#include "Cube.h"
#include "MeshLoader.h"
#include <iostream>
#include <fstream>

int Cube::numVertices = 0;
int Cube::numNormals = 0;
int Cube::numIndeces = 0;

Cube::Cube(Mesh* mesh, Texture2D* texture, float x, float y, float z) : SceneObject(mesh, texture)
{
	_rotation = rand() % 5 + 1;
	_position.x = x;
	_position.y = y;
	_position.z = z;

	_mesh = mesh;

}

Cube::~Cube()
{

}

void Cube::Draw()
{
	if (_mesh->Vertices != nullptr && _mesh->Normals != nullptr && _mesh->Indeces != nullptr)
	{

		glPushMatrix();
		
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnable(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
		glBindTexture(GL_TEXTURE_2D, _texture->GetID());
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
		glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
		glTranslatef(_position.x, _position.y, _position.z);
		glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
		glRotatef(_rotation * 2, 0.0f, 1.0f, 0.0f);
		glRotatef(_rotation / 2, 0.0f, 0.0f, 1.0f);
		glDrawElements(GL_TRIANGLES, _mesh->IndexCount, GL_UNSIGNED_SHORT, _mesh->Indeces);
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glPopMatrix();
	}
}

void Cube::Update()
{
	_rotation += rand() % 3;
	_position.z -= 0.5f;

	if (_position.z <= -120.0f)
	{
		_position.z = 0.0f;
	}
}

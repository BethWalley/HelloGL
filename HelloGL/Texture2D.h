#pragma once
#include "GlutCallbacks.h"
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#ifndef _TEXTURE2D_H
#define _TEXTURE2D_H
class Texture2D
{
public:
	Texture2D();
	~Texture2D();

	bool Load(char* path, int width, int height);

	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
protected:

private:
	GLuint _ID;

	int _width, _height;
};

#endif
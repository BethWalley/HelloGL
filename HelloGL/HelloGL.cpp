#include "HelloGL.h"
#include "MeshLoader.h"



HelloGL::HelloGL(int argc, char* argv[])
{

	InitGL(argc, argv);
	InitObjects();
	InitLighting();

	glutMainLoop();

}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (int i = 0; i < 200; i++)
	{
		cubes[i]->Draw();
	}
	for (int i = 0; i < 100; i++)
	{
		pyramids[i]->Draw();
	}
	glFlush();
	glutSwapBuffers();
}

void HelloGL::Update()
{
	for (int i = 0; i < 200; i++)
	{
		cubes[i]->Update();
	}
	for (int i = 0; i < 100; i++)
	{
		pyramids[i]->Update();
	} 
	glLoadIdentity();
	gluLookAt(camera->center.x, camera->center.y, camera->center.z, camera->eye.x, camera->eye.y, camera->eye.z, camera->up.x, camera->up.y, camera->up.z);

	glutPostRedisplay();

	if (rotation >= 360.0f)
	{
		rotation = 0.0f;
	}

	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE, &(_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, &(_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightPosition->x));
	//Sleep(10);
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	//object movement
	if (key == '+')
	{
		rotation += 2.0f;
	}
	else if (key == '-')
	{
		rotation -= 2.0f;
	}
	else if(key==' ')
	{
		rotation = 0.0f;
	}
	//camera movement
	//zooms in and out
	if (key == 'i')
	{
		camera->center.z += 0.1f;
	}
	else if (key == 'o')
	{
		camera->center.z -= 0.1f;
	}
	else if (key == ' ')
	{
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = -1.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	}
	//moves left and right
	if (key == 'r')
	{
		camera->eye.x += 0.1f;
	}
	else if (key == 'l')
	{
		camera->eye.x -= 0.1f;
	}
	else if (key == ' ')
	{
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = -1.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	}
	//moves up and down
	if (key == 'd')
	{
		camera->eye.y += 0.1f;
	}
	else if (key == 'u')
	{
		camera->eye.y -= 0.1f;
	}
	else if (key == ' ')
	{
		camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 1.0f;
		camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = -1.0f;
		camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;
	}
}

HelloGL::~HelloGL(void)
{
	camera;
}

void HelloGL::InitObjects()
{
	camera = new Camera();

	Mesh* cubeMesh = MeshLoader::Load((char*)"cube.txt");
	Mesh* pyramidMesh = MeshLoader::LoadNoTex((char*)"pyramid.txt");
	Texture2D* texture = new Texture2D();
	texture->Load((char*)"Penguins.raw", 512, 512);

	for (int i = 0; i < 200; i++)
	{
		cubes[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000) / 10.0f);
	}

	for (int i = 0; i < 100; i++)
	{
		pyramids[i] = new Pyramid(pyramidMesh, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000 / 10.0f));
	}

	camera->eye.x = 0.0f; camera->eye.y = 0.0f; camera->eye.z = 0.0f;
	camera->center.x = -5.0f; camera->center.y = -5.0f; camera->center.z = -120.0f;
	camera->up.x = 0.0f; camera->up.y = 1.0f; camera->up.z = 0.0f;

	rotation = 0.0f;

	

}

void HelloGL::InitLighting()
{
	_lightPosition = new Vector4();
	_lightPosition->x = 0.0;
	_lightPosition->y = 0.0;
	_lightPosition->z = 1.0;
	_lightPosition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;
}

void HelloGL::InitGL(int argc, char* argv[])
{

	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	//void glutInitWindowSize(int width, int height);
	//void glutInitWindowPosition(int x, int y);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glCullFace(GL_BACK);

}
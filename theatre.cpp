#include <iostream>
#include <math.h>
#include <string.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "src/chair.h"
#include "src/chairarm.h"
#include "src/fan.h"
#include "src/stair.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f, y = 2.5f;
float roll = 0.0f;

// for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

// // Fan
// Fan f;

void renderScene(void)
{

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, y, z,
			  x + lx, y + ly, z + lz,
			  roll + 0.0f, 2.5f, 0.0f);

	// Draw floor
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();

	// wall
	glColor3f(0.9294f, 0.9216f, 0.8353f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glEnd();

	// wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 0.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(-20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 0.0f, 20.0f);
	glEnd();

	// wall with door
	//  glColor3f(1.0f, 0.851f, 0.702f);
	//  glBegin(GL_QUADS);
	//  glVertex3f(-10.0f, 0.0f, 20.0f);
	//  glVertex3f(-10.0f, 7.0f, 20.0f);
	//  glVertex3f(-6.0f, 7.0f, 20.0f);
	//  glVertex3f(-6.0f, 0.0f, 20.0f);
	//  glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-17.0f, 0.0f, 20.0f);
	glVertex3f(-17.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 4.0f, 20.0f);
	glVertex3f(-17.0f, 4.0f, 20.0f);
	glVertex3f(-17.0f, 40.0f, 20.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-20.0f, 4.0f, 20.01f);
	glVertex3f(-17.0f, 4.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-20.0f, 4.0f, 20.01f);
	glVertex3f(-20.0f, 0.0f, 20.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-17.0f, 0.0f, 20.01f);
	glVertex3f(-17.0f, 4.0f, 20.01f);
	glEnd();

	// wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(20.0f, 0.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(20.0f, 0.0f, 20.0f);
	glEnd();

	// ceiling
	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, -20.0f);
	glVertex3f(20.0f, 40.0f, 20.0f);
	glVertex3f(-20.0f, 40.0f, 20.0f);
	glEnd();

	// Draw chairs and arms
	Chair chair[4][4];
	ChairArm chairArm[4][4];
	Stair stair[4];
	// for (int i = -13; i <= 13; i += 2)
	// {
	// 	for (int j = -4; j <= 4; j += 1)
	// 	{
	// 		glPushMatrix();
	// 		glTranslatef(i * 0.6, j * 1.2 + 5.0f, j * 2.0 + 2.2f);
	// 		// glScalef(0.25f, 0.25f, 0.25f);
	// 		glRotatef(180.0, 0.0, 1.0, 0.0);
	// 		// chair[i][j].drawChair();
	// 		// glTranslatef(2.45f, 0.0f, 0.0f);
	// 		// chairArm[i][j].drawChairArm();
	// 		// if (i == -3 || i == 13)
	// 		// {
	// 		// 	glTranslatef(-4.9f, 0.0f, 0.0f);
	// 		// 	chairArm[i][j].drawChairArm();
	// 		// }
	// 		// glTranslatef(-i * 0.6,  j*0.5-1.0f,  j * 2.0+2.2f);
	// 		glScalef(1.0f, 1.0f, 1.0f);

	// 		stair[j].drawStair();
	// 		// glTranslatef(-2.5f, -0.0f, -0.0f);
	// 		glPopMatrix();
	// 	}
	// 	if (i == -3)
	// 		i = 1;
	// }

	for (int i = 0; i < 9; i++)
	{
		glPushMatrix();
		glScalef(1.0f,1.0f,36.0 -(4.0*i));
		glRotatef(180.0, 0.0, 1.0, 0.0);
		glTranslatef(0.0f,i*1.0f, 1.0f);
		stair[i].drawStair();
		
		glPopMatrix();
	}
	

	// Draw Screen
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glEnd();

	// glColor3f(0.149f, 0.149f, 0.149f);
	// glBegin(GL_QUADS);
	// glVertex3f(-5.8f, 2.2f, -9.98f);
	// glVertex3f(-5.8f, 5.3f, -9.98f);
	// glVertex3f(5.8f, 5.3f, -9.98f);
	// glVertex3f(5.8f, 2.2f, -9.98f);
	// glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 25.6f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-17.0f, 25.5f, -19.99f);
	glVertex3f(17.0f, 25.5f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(17.0f, 25.6f, -19.99f);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(17.0f, 10.0f, -19.99f);
	glVertex3f(-17.0f, 10.0f, -19.99f);
	glEnd();

	// Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(3.0f);
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
		glEnd();
	}

	// Fan
	// glPushMatrix();
	// glTranslatef(0.0f, 6.0f, 0.0);
	// glScalef(0.3f, 0.3f, 0.3f);
	// f.drawFan();
	// glPopMatrix();

	glutSwapBuffers();
}

// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy)
{

	float fraction = 0.1f;

	switch (key)
	{
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

// Handles the events triggered when any key on the keyboard is pressed.
// Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy)
{
	float fraction = 1.0f;
	if (key == 'w')
	{
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a')
	{
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's')
	{
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd')
	{
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x')
	{
		roll += 0.5f;
	}
	else if (key == 'z')
	{
		roll -= 0.5f;
	}
	else if (key == 'm')
	{
		y += ly * fraction;
	}
	else if (key == 'n')
	{
		y -= ly * fraction;
	}

	if (key == 27)
		exit(0);
}

// Handles the events triggered when the mouse is moved in the window area.
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy)
{

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2))
	{
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);
}

// Adjusts the viewport sie when the window size is changed and sets the projection.
// @param w : new width of window
// @param h : new height of window
void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate()
{

	// f.rotateFan();

	/* refresh screen */
	glutPostRedisplay();
}

int main(int argc, char **argv)
{

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}
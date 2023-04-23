#include "chair.h"

void Chair ::drawChair()
{

	glColor3f(1.0f, 0.1f, 0.0f);
	glBegin(GL_QUADS);
	// chair seat
	// Front
	//
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(2.0f, -2.0f, 2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);

	// Right
	//
	glVertex3f(2.0f, -2.0f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(2.0f, -2.0f, 2.0f);

	// Back
	//;
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, -2.0f, -2.0f);

	// Left
	// ;
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);

	// top
	//

	glVertex3f(2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, 2.0f);
	glVertex3f(-2.0f, 0.2f, -2.0f);
	glVertex3f(2.0f, 0.2f, -2.0f);

	// bottom
	// ;

	glVertex3f(2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, -2.0f, 2.0f);
	glVertex3f(-2.0f, -2.0f, -2.0f);
	glVertex3f(2.0f, -2.0f, -2.0f);

	// chair back
	// front
	// chair upper part
	glColor3f(0.902, 0, 0);
	glVertex3f(-1.8f, 0.2f, -1.8f);
	glVertex3f(1.8f, 0.2f, -1.8f);
	glVertex3f(1.8f, 3.5f, -1.8f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);

	// chair upper side
	glVertex3f(-1.8f, 0.2f, -1.80f);
	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(-1.8f, 3.5f, -1.8f);

	glVertex3f(1.8f, 0.2f, -1.80f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	// chiar upper top
	glVertex3f(-1.8f, 3.5f, -1.80f);
	glVertex3f(-1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -0.6f);
	glVertex3f(1.8f, 3.5f, -1.8f);

	glVertex3f(-1.8f, 0.2f, -1.80f);
	glVertex3f(-1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -0.6f);
	glVertex3f(1.8f, 0.2f, -1.8f);

	glEnd();
}

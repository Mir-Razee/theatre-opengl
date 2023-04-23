#include "stair.h"

void Stair ::drawStair()
{

	glColor3f(0.1f, 0.0f, 0.6f);

	glBegin(GL_QUADS);
	// stair seat
	// Front
	//
	glVertex3f(-17.0f, +0.0f, 0.0f);
	glVertex3f(-17.0f, -1.0f, 0.0f);
	glVertex3f(+20.0f, -1.0f, 0.0f);
	glVertex3f(+20.0f, +0.0f, 0.0f);

	// Right
	//
	glVertex3f(+20.0f, -1.0f, +0.0f);
	glVertex3f(+20.0f, +0.0f, +0.0f);
	glVertex3f(+20.0f, +0.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);

	// Back
	//;
	glVertex3f(-17.0f, +0.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, +0.0f, -1.0f);

	// Left
	// ;
	glVertex3f(-17.0f, -1.0f, +0.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, +0.0f, -1.0f);
	glVertex3f(-17.0f, +0.0f, +0.0f);

	// top
	//

	glVertex3f(+20.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(-17.0f, -1.0f, +0.0f);
	glVertex3f(+20.0f, -1.0f, +0.0f);

	// bottom
	// ;

	glVertex3f(+20.0f, 0.0f, -1.0f);
	glVertex3f(-17.0f, 0.0f, -1.0f);
	glVertex3f(-17.0f, 0.0f, +0.0f);
	glVertex3f(+20.0f, 0.0f, +0.0f);
	glEnd();
	
	//front strip
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, +0.0f, 0.0f);
	glVertex3f(+20.0f, +0.0f, 0.0f);
	glEnd();

	//top strip
	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-17.0f, -1.0f, -1.0f);
	glVertex3f(+20.0f, -1.0f, -1.0f);
	glEnd();
}

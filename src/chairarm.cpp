#include "chairarm.h"

void ChairArm ::drawChairArm()
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    // chair seat
    // Front
    //
    glVertex3f(-0.2f, -2.0f, 0.2f);
    glVertex3f(0.2f, -2.0f, 0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);

    // Right
    //
    glVertex3f(2.0f, -2.0f, -2.0f);
    glVertex3f(2.0f, 0.2f, -2.0f);
    glVertex3f(2.0f, 0.2f, 2.0f);
    glVertex3f(2.0f, -2.0f, 2.0f);

    // Back
    //
    glVertex3f(-0.2f, -2.0f, -0.2f);
    glVertex3f(-0.2f, 2.0f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, -0.2f, -0.2f);

    // Left
    // ;
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-2.0f, -2.0f, 2.0f);
    glVertex3f(-2.0f, 0.2f, 2.0f);
    glVertex3f(-2.0f, 0.2f, -2.0f);

    // top
    //

    glVertex3f(0.2f, 0.2f, 2.0f);
    glVertex3f(-0.2f, 0.2f, 2.0f);
    glVertex3f(-0.2f, 0.2f, -2.0f);
    glVertex3f(0.2f, 0.2f, -2.0f);

    // bottom
    // ;

    glVertex3f(0.2f, -2.0f, 2.0f);
    glVertex3f(-0.2f, -2.0f, 2.0f);
    glVertex3f(-0.2f, -2.0f, -2.0f);
    glVertex3f(0.2f, -2.0f, -2.0f);

    glEnd();
}

#include "chairarm.h"

void ChairArm ::drawChairArm()
{
    glColor3f(0.9f, 0.0f, 0.1f);
    glBegin(GL_QUADS);
    // chair arm
    // Front
    //
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(0.4f, -2.0f, 2.0f);
    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);

    // Right

    glVertex3f(0.4f, -2.0f, -2.0f);
    glVertex3f(0.4f, 1.3f, -2.0f);
    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(0.4f, -2.0f, 2.0f);

    // Back

    glVertex3f(-0.4f, -2.0f, -0.2f);
    glVertex3f(0.4f, -2.0f, -0.2f);
    glVertex3f(0.4f, 1.4f, -0.2f);
    glVertex3f(-0.4f, 1.3f, -0.2f);

    // Left

    glVertex3f(-0.4f, -2.0f, -2.0f);
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, -2.0f);

    // top

    glVertex3f(0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, 2.0f);
    glVertex3f(-0.4f, 1.3f, -2.0f);
    glVertex3f(0.4f, 1.3f, -2.0f);

    // bottom

    glVertex3f(0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, -2.0f, 2.0f);
    glVertex3f(-0.4f, -2.0f, -2.0f);
    glVertex3f(0.4f, -2.0f, -2.0f);

    glEnd();
}

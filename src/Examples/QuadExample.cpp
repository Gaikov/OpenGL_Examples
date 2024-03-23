//
// Created by Roman on 3/23/2024.
//

#include "headers.h"
#include "QuadExample.h"

static float angle = 0;

bool QuadExample::Init() {

    return true;
}

void QuadExample::Update(float deltaTime) {
    angle += deltaTime * 100;

    glLoadIdentity();
    glRotated(angle, 0, 0, 1);

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-0.5, -0.5);

    glColor3f(1, 1, 0);
    glVertex2f(-0.5, 0.5);

    glColor3f(0, 1, 1);
    glVertex2f(0.5, 0.5);

    glColor3f(0, 0, 1);
    glVertex2f(0.5, -0.5);
    glEnd();
}

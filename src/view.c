/*
 * Copyright 2012 Daniil Ivanov <daniil.ivanov@gmail.com>
 *
 * This file is part of PIP-OpenGL.
 *
 * PIP-OpenGL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * PIP-OpenGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with PIP-OpenGL. If not, see http://www.gnu.org/licenses/.
 */

#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#include "view.h"

#define SIZE_X 4000.0
#define SIZE_Y 3000.0

static void drawPolygon(void)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(50., 50.);
    glVertex2f(SIZE_X - 50., 50.);
    glVertex2f(SIZE_X - 50, SIZE_Y - 50);
    glVertex2f(0., SIZE_Y - 50);
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(1.0);

    drawPolygon();

    glFlush();
}

static void reshape(GLint newWidth, GLint newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    glLoadIdentity();
    if (newWidth > newHeight) {
        GLdouble dx = SIZE_X * ((GLdouble)newWidth / newHeight - 1.0) / 2;
        glOrtho(-dx, SIZE_X + dx, 0.0, SIZE_Y, -1.0, 1.0);
    } else {
        GLdouble dy = SIZE_Y * ((GLdouble)newHeight / newWidth - 1.0) / 2;
        glOrtho(0.0, SIZE_X, -dy, SIZE_Y + dy, -1.0, 1.0);
    }
}

View *view_init(int argc, char **argv)
{
    View *view = calloc(1, sizeof(view));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH);

    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow ("PIP");

    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, SIZE_X, 0.0, SIZE_Y, -1.0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    return view;
}

void view_run(View *view)
{
    glutMainLoop();
}

View *deinit_view(View *view)
{
    if (view)
        free(view);

    return NULL;
}

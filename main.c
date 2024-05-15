//main.c, Spencer Butler, CS324 OpenGL, 11/16/2023

#include <stdio.h>
#include <stdlib.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "data.h"

int main(int argc, char **argv) {
    int item;

    if(argc < 2) {
        printf("Provide an argument to select which item to draw.\n");
        printf("\t1 -- 2D function (points)\n");
        printf("\t2 -- 2D function (lines)\n");
        printf("\t3 -- 3D function (wireframe tris)\n");
        printf("\t4 -- 3D function (all)\n");
        printf("\t5 -- Rubik's cube (no gaps)\n");
        printf("\t6 -- Rubik's cube (with gaps)\n");
        printf("\t7 -- Grid of Rubik's cubes\n");
        return 1;
    }
    item = atoi(argv[1]);

    glutInit(&argc, argv);
    glutCreateWindow("Basic OpenGL");
    glutReshapeWindow(720, 720);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    
    if(item == 1 || item == 2) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-4, 10, -2, 2, -1, 1);
    }

    if(item == 3 || item == 4) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-8, 8, -8, 8, 0, 30);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(-5.5, -8.5, 6,
                  0, 0, 0,
                  0, 0, 1);
    }

    if(item == 5 || item == 6) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, 0, 10);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(2.5, 3, 2,
                  0, 0, 0,
                  0, 0, 1);
    }

    if(item == 7) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-25, 25, -1, 40, 0, 90);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(30, 24, -5,
                  0, 0, 0,
                  0, 0, 1);
    }

    switch(item) {
        case 1:
            glutDisplayFunc(f1_points);
            break;

        case 2:
            glutDisplayFunc(f1_lines);
            break;

        case 3:
            glutDisplayFunc(f2_tw);
            break;

        case 4:
            glutDisplayFunc(f2_all);
            break;

        case 5:
            glutDisplayFunc(rubik_solid);
            break;

        case 6:
            glutDisplayFunc(rubik_gaps);
            break;

        case 7:
            glutDisplayFunc(rubik_grid);
            break;

        default:
            printf("Unrecognized item.\n");
            return 1;
    }

    glutMainLoop();

    return 0;
}


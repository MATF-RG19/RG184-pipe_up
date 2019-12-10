//GL
#include<GL/gl.h>
#include<GL/glut.h>
//C++
#include<iostream>
#include<cstdlib>
//Project headers
#include "headers/camera.hpp"
#include "headers/drawing.hpp"
#include "headers/callbacks.hpp"
#include "headers/lighting.hpp"

//External vars
extern GLUquadric* postolje;
extern GLdouble camx,camy,camz;
extern bool gridFlag;
void glutInitialization(int argc, char ** argv);
void registerCallbacks();

int main(int argc, char ** argv)
{
    glutInitialization(argc, argv);
    registerCallbacks();
    createLighting();
    pipe_quad_init();

    glutMainLoop();
    return 0;
}

void glutInitialization(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("PipeUP!");
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
}

void registerCallbacks()
{
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
}

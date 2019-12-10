//GL headers
#include<GL/gl.h>
#include<GL/glut.h>

//Other
#include<iostream>
#include<cstdlib>

#include "headers/camera.hpp"
#include "headers/drawing.hpp"
#include "headers/callbacks.hpp"

//EXTERN
extern GLUquadric* postolje;
extern GLdouble camx,camy,camz;
extern bool gridFlag;

int main(int argc, char ** argv)
{
    //Init
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("PipeUP!");
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);

//  Povezivanje callback funkcija
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    
    //Osvetljenje
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //Podesavanje osvetljenja
    GLfloat ambi[] = {0.2,.2,.2,1};
    GLfloat diff[] = {.8,.8,.8,1};
    GLfloat spec[] = {1,1,1,1};
    glLightfv(GL_LIGHT0,GL_AMBIENT, ambi);
    glLightfv(GL_LIGHT0,GL_DIFFUSE, diff);
    glLightfv(GL_LIGHT0,GL_SPECULAR, spec);

    //Pozicija svetla
    GLfloat lightpos[] = {0,10,4,1};
    glLightfv(GL_LIGHT0,GL_POSITION,lightpos);
    pipe_init();
    
    glutMainLoop();
    return 0;
}


#include<GL/gl.h>
#include<GL/glut.h>

void createLighting()
{
    //init
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
}
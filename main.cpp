//GL headers
//#include<GL/gl.h>
#include<GL/glut.h>

//Basic Headers
#include<iostream>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("PipeUP!");
    
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
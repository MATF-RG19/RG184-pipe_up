//GL headers
//#include<GL/gl.h>
#include<GL/glut.h>

//Basic Headers
#include<iostream>
#include<cstdlib>
//Testing-purpose functions
void draw_grid();
//Main callback Functions
void display();
void keyboard(unsigned char keystroke, int mousex, int mousey);

//global flags and variables
bool gridFlag = false;

int main(int argc, char ** argv)
{
    //Init Functions
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(100,100);
    glutCreateWindow("PipeUP!");
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    //registering Callback functions
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);


    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    if(gridFlag)
        draw_grid();

    glutSwapBuffers();
}

void keyboard(unsigned char keystroke, int mousex, int mousey)
{
    switch(keystroke)
    {
        case 32: //Space
            gridFlag = !gridFlag;
            glutPostRedisplay();
            break;
        case 27: //Esc
            exit(EXIT_SUCCESS);
            break;
    }
    
}

void draw_grid()
{
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(10,0,0);
        glVertex3f(0,0,0);
        glColor3f(0,1,0);
        glVertex3f(0,10,0);
        glVertex3f(0,0,0);
        glColor3f(0,0,1);
        glVertex3f(0,0,10);
        glVertex3f(0,0,0);
    glEnd();
}
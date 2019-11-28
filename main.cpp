//GL headers
#include<GL/gl.h>
#include<GL/glut.h>

//Other
#include<iostream>
#include<cstdlib>
//Funkcije testiranja
void draw_grid();
//Callback funkcije
void display();
void keyboard(unsigned char keystroke, int mousex, int mousey);

//globalflags, vars
bool gridFlag = false;

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
    //Povezivanje callback funkcija
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if(gridFlag)
        draw_grid();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex3f(0,1,0);
    glVertex3f(.5,0,0);
    glVertex3f(-.5,0,0);
    glEnd();

    


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
    GLfloat len = .3;
    glBegin(GL_LINES);
        glColor3f(1,1,1);
        glVertex3f(len,0,0);
        glVertex3f(0,0,0);
        glVertex3f(0,len,0);
        glVertex3f(0,0,0);
        glVertex3f(0,0,len);
        glVertex3f(0,0,0);
    glEnd();

    glRasterPos3f(len,0,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,'x');
    glRasterPos3f(0,len,0);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,'y');
    glRasterPos3f(0,0,len);
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,'z');
}
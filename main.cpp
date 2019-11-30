//GL headers
#include<GL/gl.h>
#include<GL/glut.h>

//Other
#include<iostream>
#include<cstdlib>
#include<math.h>
#define FONT GLUT_BITMAP_HELVETICA_10
#define PI 3.14159265359
//Funkcije
void pipe_init();
void draw_grid();
void draw();
void placeCamera();
//Callback funkcije
void display();
void keyboard(unsigned char keystroke, int mousex, int mousey);
void specialKeyboard(int key, int x, int y);

//globalflags, vars
GLUquadric* postolje;
GLdouble camx,camy,camz,angleHorizontal=0, angleVertical=0;
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
    glutSpecialFunc(specialKeyboard);

    pipe_init();
    
    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    placeCamera();


    if(gridFlag)
        draw_grid();
    
    draw();
    

    glutSwapBuffers();
}
void specialKeyboard(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
            angleVertical+=5;
            break;
        case GLUT_KEY_DOWN:
            angleVertical-=5;
            break;
        case GLUT_KEY_LEFT:
            angleHorizontal-=5;
            break;
        case GLUT_KEY_RIGHT:
            angleHorizontal+=5;
            break;
    }
    glutPostRedisplay();
}
void keyboard(unsigned char keystroke, int mousex, int mousey)
{
    switch(keystroke)
    {
        case 32: //Space
            gridFlag = !gridFlag;
            break;
        case 27: //Esc
            exit(EXIT_SUCCESS);
            break;
    }
    glutPostRedisplay();    
}

void draw_grid()
{
    GLfloat len = 2;
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
    glutBitmapCharacter(FONT,'x');
    glRasterPos3f(0,len,0);
    glutBitmapCharacter(FONT,'y');
    glRasterPos3f(0,0,len);
    glutBitmapCharacter(FONT,'z');
}

void placeCamera(){
    camx = 5*cos(angleHorizontal*PI/180)*sin(angleVertical*PI/180);
    camy = 5*sin(angleHorizontal*PI/180)*sin(angleVertical*PI/180);
    camz = 5*cos(angleVertical*PI/180);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,0.1,10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camx,camy,camz,0,0,0,0,1,0);
   
}
void pipe_init()
{
    postolje = gluNewQuadric();
    gluQuadricNormals(postolje,GLU_SMOOTH);
    gluQuadricDrawStyle(postolje,GLU_LINE);
}
void draw()
{
    //Pokusaj crtanja cevi;
    
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glColor3f(0,1,0);
    glRotatef(90,-1,0,0);
    gluCylinder(postolje,1,1,.5,10,10);
    glPopMatrix();
    /*
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex3f(0,.6,0);
        glColor3f(1,1,0);
        glVertex3f(.3,.3,0);
        glColor3f(0,1,0);
        glVertex3f(.15,0,0);
        glColor3f(0,1,1);
        glVertex3f(-.15,0,0);
        glColor3f(0,0,1);
        glVertex3f(-.3,.3,0);
    glEnd();
    glPopMatrix();
    */
}
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

//globalflags, vars
GLUquadric* postolje;
GLdouble camx,camy,camz;
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    placeCamera();


    if(gridFlag)
        draw_grid();
    
    draw();
    

    glutSwapBuffers();
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
    camx = 0;
    camy = 1;
    camz = 2;

    //Definisanje projekcije
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
    //gluQuadricDrawStyle(postolje,GLU_LINE);
}
void draw()
{
    //Postolje
    GLfloat crna[] = {0,0,0,1};
    GLfloat zuta[] = {1,1,0,1};
    GLfloat bela[] = {1,1,1,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT,bela);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,zuta);
    glMaterialfv(GL_FRONT,GL_SPECULAR,bela);
    glMaterialf(GL_FRONT,GL_SHININESS,60);


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glRotatef(90,-1,0,0);
    gluCylinder(postolje,.4,.4,.2,10,10);
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,0,0);
    for(int i = 0; i < 11; i ++)
        {
            glVertex3f(sin(i*36*PI/180)*.4,0,cos(i*36*PI/180)*.4);
        }
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,.2,0);
    for(int i = 0; i < 11; i ++)
        {
            glVertex3f(sin(i*36*PI/180)*.4,.2,cos(i*36*PI/180)*.4);
        }
    glEnd();
    glPopMatrix();
    glTranslatef(0,.2,0);
    glutSolidSphere(.2,10,10);
    glPushMatrix();
}
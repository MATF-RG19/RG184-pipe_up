#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

#define FONT GLUT_BITMAP_HELVETICA_10
#define PI 3.14159265359

GLUquadric* postolje;

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

void pipe_init()
{
    postolje = gluNewQuadric();
    gluQuadricNormals(postolje,GLU_SMOOTH);
    //gluQuadricDrawStyle(postolje,GLU_LINE);
}

void draw()
{
    //Postolje
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
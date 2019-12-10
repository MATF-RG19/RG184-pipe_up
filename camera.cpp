#include<GL/gl.h>
#include<GL/glut.h>


GLdouble camx,camy,camz;
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


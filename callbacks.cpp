#include "headers/drawing.hpp"
#include "headers/camera.hpp"

bool gridFlag=false;

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


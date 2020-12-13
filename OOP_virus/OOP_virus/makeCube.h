#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef MAKECUBE_H
#define MAKECUBE_H

class makeCube{
    public:
    int gerak[2]={5,5};
    int awalX;
    int awalY;
    int resetVertikal;
    int posisiCube[4];

    void gambarObject(){

        glPushMatrix();
        glTranslated(makeCube::awalX,makeCube::awalY,0);
        glBegin(GL_QUADS);
        glColor3b(250,100,0);
        glVertex2f(0,0);
        glVertex2f(0,5);
        glVertex2f(5,5);
        glVertex2f(5,0);
        glEnd();

        glPopMatrix();
    }

    makeCube(){
        //}
        srand (time(0));
        int a=rand() % 30;
        int b=rand() % 30;
        makeCube::awalX=a;
        makeCube::awalY=b;
        makeCube::posisiCube[2]=awalY;
         makeCube::posisiCube[3]=awalY+5;

       // makeCube::awalX=inputanx1;
        //makeCube::awalY=inputany1;
        makeCube::gambarObject();
    }

    void movement(){
        glPushMatrix();
        glTranslated(0,makeCube::awalY,0);
        makeCube();
        //makeCube::awalX=horizontal

        glPopMatrix();
    }
};

#endif



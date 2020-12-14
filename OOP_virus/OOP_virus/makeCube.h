#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#ifndef MAKECUBE_H
#define MAKECUBE_H

class makeCube{
    public:
    float gerak[2];
    int awalX;
    int awalY;
    int resetVertikal;
    float posisiCube[4];

    void gambarObject(){

        glPushMatrix();
        glTranslated(makeCube::awalX,makeCube::awalY,0);
        //glTranslated(30,30,0);
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
        glPushMatrix();
        //}
        //randPosisi+=1;
        //if (randPosisi==1){
//            srand (int time(0));
            int a=rand() % 30;
            int b=rand() % 30;
            makeCube::awalX=a;
            makeCube::awalY=b;
            makeCube::posisiCube[0]=awalX;
            makeCube::posisiCube[1]=awalX+5;
            //makeCube::posisiCube[2]=a;
            //makeCube::awalY=inputany1;
        //}
         //if (status){
            cout << "construtor" << "\n";
            float gerak[2]={0,0};
            //makeCube::awalX=30;
            makeCube::awalY=30;
            makeCube::posisiCube[2]=awalY;
            makeCube::posisiCube[3]=awalY-5;
            //makeCube::posisiCube[0]=awalX;
            //makeCube::posisiCube[1]=awalX+5;
      // }

//        makeCube::gerak[0]=0;
  //      makeCube::gerak[1]=0;
        gambarObject();
        glPopMatrix();
    }

    void movement(){
        glPushMatrix();
        cout << "movemetn" << "\n";
        glTranslated(makeCube::gerak[0],makeCube::gerak[1],0);
        //glTranslated(x,y,0);
        makeCube::gambarObject();
        //makeCube::awalX=horizontal

        glPopMatrix();
    }
};

#endif



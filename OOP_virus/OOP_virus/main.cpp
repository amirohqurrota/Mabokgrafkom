#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;


#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <fstream>

#include <cstdlib>   // rand and srand
#include <ctime>

#include "makeCube.h"

int randPosisi=0;
int posisi[4]={0,0,0,0};
int horizontal;
int vertikal;
int jumlahObjek;
makeCube listt[10];

//makeCube objek[2];



void makeMoreCube(int sumOfCubes){
    srand (time(0));
    for(int i = 0; i < sumOfCubes; i++) {
        cout <<  ":cekkk "  << "\n";

        //srand (time(0));
        //randPosisi+=1;
        //if (randPosisi==1){
            int a=rand() % 30;
            int x1=a;
            int x2=x1+5;
            int y1=rand() % 30;
            int y2=y1+5;
            cout <<  ":cekkk x1 "  <<x1<< "\n";
            cout <<  ":cekkk y1"  <<y1<< "\n";
            makeCube();
          // for(int i = 0; i < 4; i++) {
            //    cout << i << ": " << posisi[i] << "\n";
            //}
            }
}

void timerCube(){
    //listt[2].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerCube,0);
    if (listt[2].posisiCube[2]>=-0){
        listt[2].posisiCube[2]-=0.5;
        listt[2].posisiCube[2]-=0.5;
        listt[2].awalY-=0.5;
    }
    else{
        listt[2].posisiCube[2]=40;
        listt[2].posisiCube[2]=45;
        listt[2].awalY=40;
    }

}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);


    //list
    listt[2]=makeCube();

    //makeMoreCube (3);
   // makeCube objek=makeCube(0,10);
    //glTranslated(5,15,0);
    //makeCube objek2=makeCube(10,30);
    //makeCube objek3=makeCube(30,30);

    //+objek2.movement(5,25);
    cout << "posisiobjek: " << listt[1].awalX << "\n";
    //cout << "posisiobjek 1 : " << objek.awalX << "\n";
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(728, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");
	glutTimerFunc(0,timerCube,0);
	glutDisplayFunc(displayMe);
	gluOrtho2D(0,40,0,40);
	glutMainLoop();
	return 0;
}

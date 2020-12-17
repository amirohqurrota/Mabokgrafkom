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
makeCube listt[6]={makeCube(),makeCube(),makeCube(),makeCube(),makeCube(),makeCube()};
int i;
//makeCube obj1= makeCube();
bool status=true;


//makeCube objek[2];


void timerCube(int){
    //for(int i = 0; i < 2; i++){
        i=0;
        cout << "looping ke: " << i << "\n";
        listt[i].movement();
       // glutPostRedisplay();
        //glutTimerFunc(1000/30,timerCube,0);
        if (listt[i].posisiCube[3]>=0){
            cout << "if" << "\n";
            listt[i].posisiCube[2]-=0.5;
            listt[i].posisiCube[3]-=0.5;
            listt[i].gerak[1]-=1;
             //cout << "posisiobjek: " << listt[2].gerak[1] << "\n";
        }
        else{
            cout << "else " << "\n";
            listt[i].posisiCube[2]=listt[i].awalX;
            listt[i].posisiCube[3]=listt[i].awalY;
            listt[i].gerak[1]=0;
        }
      glutPostRedisplay();
      glutTimerFunc(1000/30,timerCube,0);
    }

void timerCube1(int){
    //for(int i = 0; i < 2; i++){
        i=1;
        cout << "looping ke: " << i << "\n";
        listt[i].movement();
       // glutPostRedisplay();
        //glutTimerFunc(1000/30,timerCube,0);
        if (listt[i].posisiCube[3]>=0){
            cout << "if" << "\n";
            listt[i].posisiCube[2]-=0.5;
            listt[i].posisiCube[3]-=0.5;
            listt[i].gerak[1]-=1;
             //cout << "posisiobjek: " << listt[2].gerak[1] << "\n";
        }
        else{
            cout << "else " << "\n";
            listt[i].posisiCube[2]=listt[i].awalX;
            listt[i].posisiCube[3]=listt[i].awalY;
            listt[i].gerak[1]=0;
        }
      glutPostRedisplay();
      glutTimerFunc(1000/30,timerCube1,0);
    }

void timerCube2(int){
    //for(int i = 0; i < 2; i++){
        i=2;
        cout << "looping ke: " << i << "\n";
        listt[i].movement();
       // glutPostRedisplay();
        //glutTimerFunc(1000/30,timerCube,0);
        if (listt[i].posisiCube[3]>=0){
            cout << "if" << "\n";
            listt[i].posisiCube[2]-=0.5;
            listt[i].posisiCube[3]-=0.5;
            listt[i].gerak[1]-=1;
             //cout << "posisiobjek: " << listt[2].gerak[1] << "\n";
        }
        else{
            cout << "else " << "\n";
            listt[i].posisiCube[2]=listt[i].awalX;
            listt[i].posisiCube[3]=listt[i].awalY;
            listt[i].gerak[1]=0;
        }
      glutPostRedisplay();
      glutTimerFunc(1000/30,timerCube2,0);
    }

void timerCube3(int){
    //for(int i = 0; i < 2; i++){
        i=3;
        cout << "looping ke: " << i << "\n";
        listt[i].movement();
       // glutPostRedisplay();
        //glutTimerFunc(1000/30,timerCube,0);
        if (listt[i].posisiCube[3]>=0){
            cout << "if" << "\n";
            listt[i].posisiCube[2]-=0.5;
            listt[i].posisiCube[3]-=0.5;
            listt[i].gerak[1]-=1;
             //cout << "posisiobjek: " << listt[2].gerak[1] << "\n";
        }
        else{
            cout << "else " << "\n";
            listt[i].posisiCube[2]=listt[i].awalX;
            listt[i].posisiCube[3]=listt[i].awalY;
            listt[i].gerak[1]=0;
        }
      glutPostRedisplay();
      glutTimerFunc(1000/30,timerCube3,0);
    }

void timerCube4(int){
    //for(int i = 0; i < 2; i++){
        i=4;
        cout << "looping ke: " << i << "\n";
        listt[i].movement();
       // glutPostRedisplay();
        //glutTimerFunc(1000/30,timerCube,0);
        if (listt[i].posisiCube[3]>=0){
            cout << "if" << "\n";
            listt[i].posisiCube[2]-=0.5;
            listt[i].posisiCube[3]-=0.5;
            listt[i].gerak[1]-=1;
             //cout << "posisiobjek: " << listt[2].gerak[1] << "\n";
        }
        else{
            cout << "else " << "\n";
            listt[i].posisiCube[2]=listt[i].awalX;
            listt[i].posisiCube[3]=listt[i].awalY;
            listt[i].gerak[1]=0;
        }
      glutPostRedisplay();
      glutTimerFunc(1000/30,timerCube4,0);
    }


void text(int x, int y, const char *string, void *font, float r, float g, float b){
    // glScaled(1.5,1.5,0);

    glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(font, string[i]);
	}
}

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

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    bool status=false;
    //makeCube obj1= makeCube();
    glPushMatrix();
    glTranslatef(-18, 0, 0); //-(5x4)+5 // -((lebar+scaled)+x-0) //-20+7 // -((x-0)*scaled)+lebar
    glScaled(5,5,0);
    glBegin(GL_QUADS);
        glColor3b(250,100,0);
        glVertex2f(5,0);
        glVertex2f(5,5);
        glVertex2f(12,5);
        glVertex2f(12,0);
        glEnd();
    glPopMatrix();
   // glScalef(2,2,0);
    text(6,5,"MENU :",GLUT_BITMAP_HELVETICA_18,0.0f,1.0f,1.0f);

    //listt[0]=makeCube();
    //obj1.gerak[0]=-20;
     //for(int i = 0; i < 6 ; i++){
      //   listt[i].movement();
      //   cout << "posisiobjek x : " << listt[i].posisiCube[0] << "\n";
   // }


    //listt[0].movement();

   // listt[1]=makeCube();


    //makeMoreCube (3);
   // makeCube objek=makeCube(0,10);
    //glTranslated(5,15,0);
    //makeCube objek2=makeCube(10,30);
    //makeCube objek3=makeCube(30,30);

    //+objek2.movement(5,25);

    cout << "posisiobjek x : " << listt[2].posisiCube[0] << "\n";
    cout << "posisiobjek y : " << listt[2].posisiCube[1] << "\n";
	glutSwapBuffers();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(728, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");

	glutDisplayFunc(displayMe);
	gluOrtho2D(0,40,0,40);
	glutMainLoop();
	return 0;
}

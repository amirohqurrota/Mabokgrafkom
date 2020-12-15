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
#include "Virus.h"


int horizontal=0;
int vertikalObat=45;
float posisiObat[4]={20,25,38,45};
int colliderWindowRight=85;
int colliderWindowLeft=0;
int colliderWindowTop=45;
int colliderWindowBottom=0;
float colliderDokter[4]={0,8,0,7};
Virus arrayVirus[20];

int i;
bool status=true;





//char MENU[1000];

void cek(){
    cout << "posisiKanan: " << colliderDokter[1] << "\n";
    cout << "WindowRight: " << colliderWindowRight<< "\n";
    cout << "posisiKiri: " << colliderDokter[0] << "\n";
    cout << "WindowLeft: " << colliderWindowLeft<< "\n";
    cout << "Translasi: " << horizontal<< "\n";


}
void text(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}
void menu(){
    glPushMatrix();
    glBegin(GL_POLYGON);
	glColor3b(100,100,100);
	glVertex2f(35,35);
	glVertex2f(55,35);
	glVertex2f(55,10);
	glVertex2f(35,10);
	glEnd();
    glColor3b(100,0,0);
    text(42,33,"MENU :");

    glPopMatrix();
}
void gerakDokter(int key, int x, int y){
    cek();
    if(GetAsyncKeyState(VK_RIGHT)){
        if (colliderDokter[1]<=colliderWindowRight){
            horizontal+=3;
            colliderDokter[1]+=3;
            colliderDokter[0]+=3;
            glutPostRedisplay();
        }
    }
    if (GetAsyncKeyState(VK_LEFT)){
        if (colliderDokter[0]>=colliderWindowLeft){
            horizontal-=3;
            colliderDokter[1]-=3;
            colliderDokter[0]-=3;
            glutPostRedisplay();
        }
    }

}


void dokterObject(){
    glPushMatrix();
    glLineWidth(5);
    glBegin(GL_POLYGON); //APD luar
	glColor3f(0.8f, 0.8f, 0.9f);
	glVertex2f(1.86,9.83);//A
	glVertex2f(1.04,8.95);//B
	glVertex2f(0.62,8.03);//C
	glVertex2f(0.6,6.85);//D
	glVertex2f(0.64,5.71);//E
	glVertex2f(1.24,4.73);//F
	glVertex2f(2.2,3.91);//G
	glVertex2f(4.2,3.91);//O
	glVertex2f(5.04,4.71);//N
	glVertex2f(5.84,5.75);//M
	glVertex2f(5.92,6.89);//L
	glVertex2f(5.92,8.01);//K
	glVertex2f(5.52,8.95);//J
	glVertex2f(4.82,9.83);//I
	glVertex2f(3.34,9.91);//H
	glEnd();

	glBegin(GL_POLYGON);//Leher
	glColor3f (0.5, 0.5, 0.5);
	glVertex2f(2.2,3.91);//G
	glVertex2f(4.2,3.91);//O
	glVertex2f(6.2,1.91);//Z
	glVertex2f(6.3068, 0);//J1
	glVertex2f(0, 0);//I1
	glVertex2f(0.2,1.91);//W
	glEnd();

    glBegin(GL_POLYGON);//atas kacamata
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(2.34,8.91);//R
	glVertex2f(4.2,8.91);//S
	glVertex2f(5.04,7.81);//T
	glVertex2f(1.36,7.83);//Q
	glEnd();

	glBegin(GL_POLYGON);//Masker
	glColor3f(0.0f,1.0f,1.0f);
	glVertex2f(3.18,6.45);//V
	glVertex2f(5.1,5.49);//U
	glVertex2f(4.2,3.91);//O
	glVertex2f(2.2,3.91);//G
	glVertex2f(1.32,5.55);//P
    glEnd();

    glBegin(GL_POLYGON);//Kacamata
    glColor3f(1.0f,0.4f,0.0f);
    glVertex2f(3.18,6.45);//V
    glVertex2f(5.1,5.49);//U
    glVertex2f(5.04,7.81);//T
    glVertex2f(1.36,7.83);//Q
    glVertex2f(1.32,5.55);//P
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline Kacamata
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(3.18,6.45);//V
    glVertex2f(5.1,5.49);//U
    glVertex2f(5.04,7.81);//T
    glVertex2f(1.36,7.83);//Q
    glVertex2f(1.32,5.55);//P
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline Atas Kacamata
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(2.34,8.91);//R
	glVertex2f(4.2,8.91);//S
	glVertex2f(5.04,7.81);//T
	glVertex2f(1.36,7.83);//Q
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline APD + Leher
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(0.2,1.91);//W
    glVertex2f(2.2,3.91);//G
    glVertex2f(1.24,4.73);//F
    glVertex2f(0.64,5.71);//E
    glVertex2f(0.6,6.85);//D
    glVertex2f(0.62,8.03);//C
    glVertex2f(1.04,8.95);//B
    glVertex2f(1.86,9.83);//A
	glVertex2f(3.34,9.91);//H
	glVertex2f(4.82,9.83);//I
	glVertex2f(5.52,8.95);//J
	glVertex2f(5.92,8.01);//K
	glVertex2f(5.92,6.89);//L
	glVertex2f(5.84,5.75);//M
	glVertex2f(5.04,4.71);//N
	glVertex2f(4.2,3.91);//O
	glVertex2f(6.2,1.91);//Z
	glVertex2f(6.3068, 0);//J1
	glVertex2f(0, 0);//I1
	glVertex2f(0.2,1.91);//W
	glEnd();


	glBegin(GL_LINE_LOOP);//Outline Masker
    glColor3f(0.2f, 0.3f, 0.4f);
	glVertex2f(3.18,6.45);//V
	glVertex2f(5.1,5.49);//U
	glVertex2f(4.2,3.91);//O
	glVertex2f(2.2,3.91);//G
	glVertex2f(1.32,5.55);//P
	glEnd();

	glPointSize(10);//mata luar
    glBegin(GL_POINTS);
    glColor3f (0.0, 0.0, 0.0);
    glVertex2f(2.38,6.93);//A1
    glVertex2f(4.2,6.91);//B1
    glEnd();

    glPointSize(3);//bayangan mata
    glBegin(GL_POINTS);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex2f(2.28,7.13);//C1
    glVertex2f(4.08,7.09);//D1
    glEnd();

    glLineWidth(03);//strip bayangan masker atas
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex2f(2.22,5.41);//E1
    glVertex2f(4.08,5.41);//F1
    glEnd();

    glLineWidth(03);//strip bayangan masker bawah
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex2f(2.62,4.83);//G1
    glVertex2f(3.84,4.83);//H1
    glEnd();

    glLineWidth(03);//strip resleting
    glBegin(GL_LINES);
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex2f(3.1608,3.91);//K1
    glVertex2f(3.1608,0);//L1
    glEnd();
    glPopMatrix();
	glutSwapBuffers();
}

void dokterMove(){
    glPushMatrix();
    glTranslated(horizontal,0,0);
    glScaled(1.1,1.1,0);
    dokterObject();
	glPopMatrix();
}

void obatObject(){
    glPushMatrix();
    glTranslated(0,vertikalObat,0);
    glTranslated(25,30,0);

    glBegin(GL_POLYGON); //Badan obat1
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(0,0);
	glVertex2f(5,0);
	glVertex2f(5,4);
	glVertex2f(0,4);
	glEnd();

	glBegin(GL_POLYGON); //badan obat2
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(4,4);
	glVertex2f(4,5);
	glVertex2f(1,5);
	glVertex2f(1,4);
	glEnd();

	glBegin(GL_POLYGON); //badan obat3
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(3.32,5);
	glVertex2f(3.32,5.98);
	glVertex2f(1.61,5.96);
	glVertex2f(1.59,5);
	glEnd();

	glBegin(GL_POLYGON); //pencetan vertikal
	glColor3f(1,1,1);
	glVertex2f(2.59,5.98);
	glVertex2f(2.59,6.99);
	glVertex2f(2.4,6.99);
	glVertex2f(2.4,5.97);
	glEnd();

	glBegin(GL_POLYGON); //pencetan horizontal
	glColor3f(1,1,1);
	glVertex2f(1.59,7.01);
	glVertex2f(1.59,6.76);
	glVertex2f(2.59,6.76);
	glVertex2f(2.59,7.01);
	glEnd();

	glBegin(GL_POLYGON); //palang merah vertikal
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(2,3);
	glVertex2f(3,3);
	glVertex2f(3,1);
	glVertex2f(2,1);
	glEnd();

    glBegin(GL_POLYGON); //palang merah horizontal
    glColor3f(1.0, 0.0, 0.0);
	glVertex2f(1.0,2.49);
	glVertex2f(3.98,2.47);
	glVertex2f(3.98,1.47);
	glVertex2f(1.0,1.49);
	glEnd();
	glPopMatrix();


}

void timerObat(int){
    obatObject();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerObat,0);
    if (posisiObat[3]>=-0){
        posisiObat[2]-=0.5;
        posisiObat[3]-=0.5;
        vertikalObat-=1;
    }
    else{
        posisiObat[2]=40;
        posisiObat[3]=47;
        vertikalObat=45;
    }

}

void timerVirus(int){
    i=0;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}
void timerVirus1(int){
    i=1;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus1,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus2(int){
    i=2;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus2,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus3(int){
    i=3;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus3,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus4(int){
    i=4;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus4,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus5(int){
    i=5;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus5,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus6(int){
    i=6;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus6,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus7(int){
    i=7;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus7,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus8(int){
    i=8;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus8,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}

void timerVirus9(int){
    i=9;
    arrayVirus[i].movement();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus9,0);
    if (arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].verVirus){
        arrayVirus[i].gerakVirus[1]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[2]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[3]-=arrayVirus[i].kecepatanVirus;
    }
    if (arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]+=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]+=arrayVirus[i].kecepatanVirus;
    }
    if (!arrayVirus[i].horVirus){
        arrayVirus[i].gerakVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[0]-=arrayVirus[i].kecepatanVirus;
        arrayVirus[i].colliderVirus[1]-=arrayVirus[i].kecepatanVirus;
    }

    //sisikanan
    if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]>=85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45 ){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
    //sisiatas
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]>=45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }
    //sisibawah
    else if (arrayVirus[i].colliderVirus[0]>0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]<=0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].verVirus=!arrayVirus[i].verVirus;
    }


    //sisikiri

    else if (arrayVirus[i].colliderVirus[0]<=0 && arrayVirus[i].colliderVirus[1]<85 && arrayVirus[i].colliderVirus[2]>0 && arrayVirus[i].colliderVirus[3]<45){
        arrayVirus[i].horVirus=!arrayVirus[i].horVirus;
    }
}



void score




void virusDisplay(int sumOfVirus){
        for(int i = 0; i < sumOfVirus; i++) {
        arrayVirus[i].movement();

    }
    }


void virusRand(){
    if (status){
        srand(time(NULL));
        for(int i = 0; i < 10; i++) {
        int a=rand() % 80+1;
        int b=rand() % 40+1;
        arrayVirus[i].verVirus = rand() & 1;
        arrayVirus[i].horVirus = rand() & 1;
        arrayVirus[i].posisiAwal[0]=a;
        arrayVirus[i].posisiAwal[1]=b;
        arrayVirus[i].colliderVirus[0]=a;
        arrayVirus[i].colliderVirus[1]=a+5;
        arrayVirus[i].colliderVirus[2]=b;
        arrayVirus[i].colliderVirus[3]=b+5;
        arrayVirus[i].gerakVirus[0]=0;
        arrayVirus[i].gerakVirus[1]=0;

    }
    }

}

void backgroundObject(){
    glPushMatrix();
    glScaled(0.57,0.43,0);
    glBegin(GL_POLYGON); //langit biru
	glColor3f(0.824, 0.937, 0.992);
	glVertex2f(0, 36);
	glVertex2f(0, 107);
	glVertex2f(149, 107);
	glVertex2f(149, 36);
	glEnd();

	glBegin(GL_POLYGON); //rumput hijau
	glColor3f(0.2, 0.8, 0.4);
	glVertex2f(0, 36);
	glVertex2f(0, 17);
	glVertex2f(149, 17);
	glVertex2f(149, 36);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat muda seharusnya
	glColor3f(0.58, 0.467, 0.294);
	glVertex2f(0, 18);
	glVertex2f(0, 8);
	glVertex2f(150, 8);
	glVertex2f(150, 18);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat tua seharusnya
	glColor3f(0.467, 0.373, 0.239);
	glVertex2f(0, 8);
	glVertex2f(0, 0);
	glVertex2f(150, 0);
	glVertex2f(150, 8);
	glEnd();

    glBegin(GL_POLYGON); //matahari
    glColor3f(1, 1, 0.4);
	glVertex2f(18.74804, 103.75981);
	glVertex2f(19.43656, 103.73829);
	glVertex2f(20.2757, 103.58768);
	glVertex2f(21.0718, 103.41555);
	glVertex2f(21.997, 103.13583);
	glVertex2f(22.79311, 102.79157);
	glVertex2f(23.48163, 102.36125);
	glVertex2f(24, 102);
	glVertex2f(24.66503, 101.52211);
	glVertex2f(25.13839, 100.96269);
	glVertex2f(25.71933, 100.53236);
	glVertex2f(26, 100);
	glVertex2f(26.47291, 99.52634);
	glVertex2f(26.73104, 99.17435);
	glVertex2f(26.96571, 98.75195);
	glVertex2f(27.20038, 98.23568);
	glVertex2f(27.41158, 97.74288);
	glVertex2f(27.74011, 96.78075);
	glVertex2f(28, 96);
	glVertex2f(27.88091, 95.18502);
	glVertex2f(27.95131, 94.69222);
	glVertex2f(28, 94);
	glVertex2f(27.88091, 93.63622);
	glVertex2f(27.76713, 93.18907);
	glVertex2f(27.70667, 92.67514);
	glVertex2f(27.49505, 92.13098);
	glVertex2f(27.28343, 91.61705);
	glVertex2f(27.21958, 91.23002);
	glVertex2f(26.94055, 90.83141);
	glVertex2f(26.82842, 90.59847);
	glVertex2f(26.68131, 90.34437);
	glVertex2f(26.54758, 90.1304);
	glVertex2f(26.45396, 89.9298);
	glVertex2f(26.29348, 89.75595);
	glVertex2f(26.14638, 89.51523);
	glVertex2f(25.86553, 89.28788);
	glVertex2f(25.71843, 89.06053);
	glVertex2f(25.50445, 88.75295);
	glVertex2f(25.19687, 88.56572);
	glVertex2f(24.9294, 88.33837);
	glVertex2f(24.56832, 87.99067);
	glVertex2f(24.28748, 87.79007);
	glVertex2f(24.04676, 87.65633);
	glVertex2f(23.84616, 87.48248);
	glVertex2f(23.49845, 87.28188);
	glVertex2f(23.13737, 87.05453);
	glVertex2f(22.70943, 86.8673);
	glVertex2f(22.3216, 86.68008);
	glVertex2f(21.80004, 86.4661);
	glVertex2f(21.29185, 86.29225);
	glVertex2f(20.78366, 86.17189);
	glVertex2f(20.18186, 86.02478);
	glVertex2f(19.74054, 85.97129);
	glVertex2f(19, 86);
	glVertex2f(18.48345, 85.9178);
	glVertex2f(17.60081, 85.94454);
	glVertex2f(17.37346, 85.98466);
	glVertex2f(17, 86);
	glVertex2f(16.438, 86.18892);
	glVertex2f(15.95241, 86.34289);
	glVertex2f(15.44313, 86.56792);
	glVertex2f(15.0523, 86.82847);
	glVertex2f(14.47196, 87.0535);
	glVertex2f(14.18771, 87.32591);
	glVertex2f(13.78503, 87.57462);
	glVertex2f(13.35866, 87.88255);
	glVertex2f(12.87307, 88.33261);
	glVertex2f(12.52961, 88.6287);
	glVertex2f(12.05586, 89.22088);
	glVertex2f(11.81899, 89.54066);
	glVertex2f(11.58212, 89.78937);
	glVertex2f(11.41631, 90.06178);
	glVertex2f(11.2505, 90.3934);
	glVertex2f(11.03732, 90.73686);
	glVertex2f(11, 91);
	glVertex2f(10.71754, 91.43564);
	glVertex2f(10.58726, 91.81463);
	glVertex2f(10.46882, 92.16994);
	glVertex2f(10.30301, 92.58446);
	glVertex2f(10.20518, 92.98475);
	glVertex2f(10.11231, 93.52872);
	glVertex2f(10.09904, 93.80733);
	glVertex2f(10.0725, 94.21863);
	glVertex2f(10.04597, 94.60338);
	glVertex2f(10, 95);
	glVertex2f(10.0725, 95.4127);
	glVertex2f(10.16538, 96.04954);
	glVertex2f(10.25825, 96.80579);
	glVertex2f(10.35112, 97.21708);
	glVertex2f(10.48379, 97.70798);
	glVertex2f(10.643, 98.26521);
	glVertex2f(10.88182, 98.76937);
	glVertex2f(11.25331, 99.41948);
	glVertex2f(11.55799, 99.86279);
	glVertex2f(12.01186, 100.55872);
	glVertex2f(12.39009, 100.98234);
	glVertex2f(12.79857, 101.43621);
	glVertex2f(13.31296, 101.76905);
	glVertex2f(13.96351, 102.22292);
	glVertex2f(14.40225, 102.51037);
	glVertex2f(15.00741, 102.84321);
	glVertex2f(15.79412, 103.17605);
	glVertex2f(16.39929, 103.41811);
	glVertex2f(17.04984, 103.56941);
	glVertex2f(17.67013, 103.70557);
	glVertex2f(18.27529, 103.8266);
	glEnd();

	glBegin(GL_POLYGON); //atap kiri
	glColor3f(0.4, 0.2, 0.2);
	glVertex2f(48, 65);
	glVertex2f(63, 65);
	glVertex2f(63, 60);
	glVertex2f(48, 60);
	glEnd();

	glBegin(GL_POLYGON); //badan kecil kiri
	glColor4f(1.0f,1.0f,1.0f,0.0f);
	glVertex2f(63, 60);
	glVertex2f(49, 60);
	glVertex2f(49, 36);
	glVertex2f(63, 36);
	glEnd();

	glBegin(GL_POLYGON); //kaca kiri atas
	glColor3f(0.4, 0.6, 1);
	glVertex2f(54, 57);
	glVertex2f(54, 51);
	glVertex2f(59, 51);
	glVertex2f(59, 57);
	glEnd();

	glBegin(GL_POLYGON); //kaca kiri bawah
	glColor3f(0.4, 0.6, 1);
	glVertex2f(54, 47);
	glVertex2f(54, 41);
	glVertex2f(59, 41);
	glVertex2f(59, 47);
	glEnd();

	glBegin(GL_POLYGON); //atap tengah
	glColor3f(0.4, 0.2, 0.2);
	glVertex2f(62, 81);
	glVertex2f(62, 76);
	glVertex2f(91, 76);
	glVertex2f(91, 81);
	glEnd();

	glBegin(GL_POLYGON); //badan tengah
	glColor4f(1.0f,1.0f,1.0f,0.0f);
	glVertex2f(63, 76);
	glVertex2f(63, 30);
	glVertex2f(90, 30);
	glVertex2f(90, 76);
	glEnd();

	glBegin(GL_POLYGON); //kaca tengah kiri
	glColor3f(0.4, 0.6, 1);
	glVertex2f(68, 55);
	glVertex2f(73, 55);
	glVertex2f(73, 50);
	glVertex2f(68, 50);
	glEnd();

	glBegin(GL_POLYGON); //kaca tengah kanan
	glColor3f(0.4, 0.6, 1);
	glVertex2f(80, 55);
	glVertex2f(85, 55);
	glVertex2f(85, 50);
	glVertex2f(80, 50);
	glEnd();

	glBegin(GL_POLYGON); //tanda merah vertikal
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(74, 72);
	glVertex2f(78, 72);
	glVertex2f(78, 61);
	glVertex2f(74, 61);
	glEnd();

	glBegin(GL_POLYGON); //tanda merah horizontal
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(70, 69);
	glVertex2f(82, 69);
	glVertex2f(82, 65);
	glVertex2f(70, 65);
	glEnd();

	glBegin(GL_POLYGON); //pintu abu
	glColor3f(0.2, 0.2, 0.2);
	glVertex2f(70, 45);
	glVertex2f(82, 45);
	glVertex2f(82, 30);
	glVertex2f(70, 30);
	glEnd();

	glBegin(GL_POLYGON); //atap kanan
	glColor3f(0.4, 0.2, 0.2);
	glVertex2f(90, 65);
	glVertex2f(106, 65);
	glVertex2f(106, 60);
	glVertex2f(90, 60);
	glEnd();

	glBegin(GL_POLYGON); //badan kanan
	glColor4f(1.0f,1.0f,1.0f,0.0f);
	glVertex2f(90, 60);
	glVertex2f(105, 60);
	glVertex2f(105, 36);
	glVertex2f(90, 36);
	glEnd();

	glBegin(GL_POLYGON); //kaca kanan atas
	glColor3f(0.4, 0.6, 1);
	glVertex2f(93, 57);
	glVertex2f(98, 57);
	glVertex2f(98, 51);
	glVertex2f(93, 51);
	glEnd();

	glBegin(GL_POLYGON); //kaca kanan bawah
	glColor3f(0.4, 0.6, 1);
	glVertex2f(93, 47);
	glVertex2f(98, 47);
	glVertex2f(98, 41);
	glVertex2f(93, 41);
	glEnd();


	glPopMatrix();

}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

    backgroundObject();
    menu();
    virusRand();
    virusDisplay(5);
    virusDisplay(10);
  // Virus();
    dokterMove();
    obatObject();

   // for(int i = 0; i < 6 ; i++){

        // arrayVirus[4].movement();
         //arrayVirus[5].movement();
         //cout << "posisiobjek x : " << listt[i].posisiCube[0] << "\n";
   // }
   // randVirus();
    //virusObject();
    status=false;
    glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");
	glutDisplayFunc(displayMe);
	glutSpecialFunc(gerakDokter);
	glutTimerFunc(0,timerObat,0);
    glutTimerFunc(0,timerVirus,0);
    glutTimerFunc(0,timerVirus4,0);
    glutTimerFunc(0,timerVirus2,0);
    glutTimerFunc(0,timerVirus1,0);
    glutTimerFunc(0,timerVirus3,0);
    glutTimerFunc(0,timerVirus5,0);
    glutTimerFunc(0,timerVirus6,0);
    glutTimerFunc(0,timerVirus7,0);
    glutTimerFunc(0,timerVirus8,0);
    glutTimerFunc(0,timerVirus9,0);

	//glutSpecialFunc(randVirus);

	gluOrtho2D(0, 85, 0, 45); //85,45
	glutMainLoop();
	return 0;
}

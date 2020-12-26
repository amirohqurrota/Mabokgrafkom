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
//#include "CollVirus.h"


int horizontal=0;
int gerakObat[2]={0,0};
int obatAwal[2]={40,45};
float colliderObat[4]={40,45,45,52};
int colliderWindowRight=85;
int colliderWindowLeft=0;
int colliderWindowTop=45;
int colliderWindowBottom=0;

float colliderDokter[4]={0,7,0,11};
float gerakDokter[2]={0,0};
bool horDokter=true;

Virus arrayVirus[10];

int i;
bool status=true; //andVirus
bool statusDeleteVirus=true;

int imunitas=30;
int scorePoin=0;
int pertambahanPoin=2;
bool scoreStatus=true;
char finalPoin[1000];

bool playStatus=false;
bool mode1Status=true;
bool gameOverStatus=false;





//char MENU[1000];

void cek(){
    cout << "posisiKanan: " << colliderDokter[1] << "\n";
    cout << "WindowRight: " << colliderWindowRight<< "\n";
    cout << "posisiKiri: " << colliderDokter[0] << "\n";
    cout << "WindowLeft: " << colliderWindowLeft<< "\n";
    cout << "Translasi: " << horizontal<< "\n";


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
void menu1(){
    glPushMatrix();//BG
    glScaled(0.6,0.4,0);
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

    glPopMatrix();


    glPushMatrix();//AWAS KOPIT
    glScaled(0.5,0.5,0);
    glTranslated(42, 28, 0);
    glLineWidth(10);


    glBegin(GL_LINES); //Huruf A lengkung
	glColor3f(0, 0, 0);
	glVertex2f(19.5525, 25.2593749999998);//I
	glVertex2f(19.5525, 27.1493749999998);//J
	glVertex2f(20.0025, 27.1493749999998);//K
	glVertex2f(20, 30);//L
	glVertex2f(20.4075, 29.9843749999998);//M
	glVertex2f(20.39, 32.2643749999998);//N
	glVertex2f(22.57, 32.2643749999998);//O
	glVertex2f(22.5675, 29.9843749999998);//P
	glVertex2f(23.0175, 29.9843749999998);//Q
	glVertex2f(22.8375, 27.1943749999998);//R
	glVertex2f(23.2875, 27.1943749999998);//S
	glVertex2f(23.1525, 25.3943749999998);//T
	glEnd();

	glBegin(GL_LINES); //Huruf A lurus atas
	glColor3f(0, 0, 0);
	glVertex2f(20.39, 32.2643749999998);//N
	glVertex2f(22.57, 32.2643749999998);//O
	glEnd();

	glBegin(GL_LINES); //Huruf A lurus bawah
	glColor3f(0, 0, 0);
	glVertex2f(20.0025, 27.1493749999998);//K
	glVertex2f(22.8375, 27.1943749999998);//R
	glEnd();

	glBegin(GL_LINES);//huruf W
	glColor3f(0, 0, 0);
	glVertex2f(24.1425, 32.3693749999998);//U
	glVertex2f(24.1425, 31.0193749999998);//V
	glVertex2f(24.6825, 31.0193749999998);//W
	glVertex2f(24.4575, 28.7243749999998);//Z
	glVertex2f(24.9525, 28.7243749999998);//A1
	glVertex2f(24.8175, 26.7893749999998);//B1
	glVertex2f(25.4925, 26.8343749999998);//C1
	glVertex2f(25.43, 25.3643749999998);//D1
	glVertex2f(26.1675, 26.8343749999998);//E1
	glVertex2f(26.2125, 28.9943749999998);//F1
	glVertex2f(26.8425, 28.9943749999998);//G1
	glVertex2f(26.8875, 26.8343749999998);//H1
	glVertex2f(27.45, 26.7243749999998);//I1
	glVertex2f(27.47, 25.3843749999998);//J1
	glVertex2f(28.09, 26.6843749999998);//K1
	glVertex2f(28, 29);//L1
	glVertex2f(28.49, 29.0443749999998);//M1
	glVertex2f(28.4699999999999, 30.9443749999998);//N1
	glVertex2f(28.8499999999999, 30.9243749999998);//O1
	glVertex2f(28.8299999999999, 32.3443749999998);//P1
	glEnd();

	glBegin(GL_LINES); //Huruf A lengkung
	glColor3f(0, 0, 0);
	glVertex2f(29.7299999999999, 25.3843749999998);//Q1
	glVertex2f(29.6899999999999, 27.0243749999998);//R1
	glVertex2f(30, 27);//S1
	glVertex2f(30, 30);//T1
	glVertex2f(30.4299999999999, 29.9843749999998);//U1
	glVertex2f(30.3699999999999, 32.2843749999998);//V1
	glVertex2f(32.7299999999999, 32.3443749999998);//W1
	glVertex2f(32.7299999999999, 30.0443749999998);//Z1
	glVertex2f(33.1499999999999, 30.0443749999998);//A2
	glVertex2f(33.1299999999999, 27.1243749999998);//B2
	glVertex2f(33.4699999999999, 27.1243749999998);//C2
	glVertex2f(33.3899999999999, 25.3843749999998);//D2
	glEnd();

	glBegin(GL_LINES); //Huruf A lurus atas
	glColor3f(0, 0, 0);
	glVertex2f(30.3699999999999, 32.2843749999998);//V1
	glVertex2f(32.7299999999999, 32.3443749999998);//W1
	glEnd();

	glBegin(GL_LINES); //Huruf A lurus bawah
	glColor3f(0, 0, 0);
	glVertex2f(30, 27);//S1
	glVertex2f(33.1299999999999, 27.1243749999998);//B2
	glEnd();

	glBegin(GL_LINES); //Huruf S
	glColor3f(0, 0, 0);
	glVertex2f(34.9899999999999, 26.4443749999998);//E2
	glVertex2f(34.9699999999999, 25.7643749999998);//F2
	glVertex2f(35.2299999999999, 25.4443749999998);//G2
	glVertex2f(37.4499999999999, 25.4443749999998);//H2
	glVertex2f(37.8899999999999, 25.7443749999998);//I2
	glVertex2f(37.8899999999999, 28.3443749999998);//J2
	glVertex2f(37.4499999999999, 28.6443749999998);//K2
	glVertex2f(35.4499999999999, 28.6243749999998);//L2
	glVertex2f(34.9699999999999, 28.7643749999998);//M2
	glVertex2f(35, 32);//N2
	glVertex2f(35.3499999999999, 32.2243749999998);//O2
	glVertex2f(37.3899999999999, 32.2643749999998);//P2
	glVertex2f(38, 32);//Q2
	glVertex2f(38.0499999999999, 31.2443749999998);//R2
	glEnd();

	glBegin(GL_LINES);//Huruf K lurus
	glColor3f(1, 0.016, 0.016);
	glVertex2f(42.4705263157899, 32.5357625598085);//S2
	glVertex2f(42.4059330143545, 25.0860017942583);//T2
	glEnd();

	glBegin(GL_LINES);//Huruf K lengkung atas
	glColor3f(1, 0.016, 0.016);
	glVertex2f(42.6299999999999, 28.7443749999998);//U2
	glVertex2f(44.6451674641152, 28.7893510765549);//V2
	glVertex2f(44.6451674641152, 28.7893510765549);//V2
	glVertex2f(43.4899999999999, 29.1443749999998);//W2
	glVertex2f(44.6899999999998, 29.1643749999998);//Z2
	glVertex2f(44.6899999999998, 30.4643749999998);//A3
	glVertex2f(45.0499999999998, 30.4843749999998);//B3
	glVertex2f(45.0299999999999, 32.2243749999998);//C3
	glEnd();

	glBegin(GL_LINES);//Huruf K lengkung bawah
	glColor3f(1, 0.016, 0.016);
	glVertex2f(42.6299999999999, 28.7443749999998);//U2
	glVertex2f(44.6451674641152, 28.7893510765549);//V2
	glVertex2f(44.6451674641152, 28.7893510765549);//V2
	glVertex2f(43.4699999999999, 28.0643749999998);//D3
	glVertex2f(44.7299999999998, 28.0643749999998);//E3
	glVertex2f(44.6899999999998, 26.7243749999998);//F3
	glVertex2f(45.1299999999998, 26.6843749999998);//G3
	glVertex2f(45.0699999999999, 25.3243749999998);//H3
	glEnd();

	glBegin(GL_LINES);//Huruf O
	glColor3f(1, 0.016, 0.016);
	glVertex2f(46.9299999999998, 31.5843749999998);//I3
	glVertex2f(47, 26);//J3
	glVertex2f(47.3499999999998, 25.5443749999998);//K3
	glVertex2f(50.0299999999998, 25.4843749999998);//L3
	glVertex2f(50.4699999999998, 25.9643749999998);//M3
	glVertex2f(50.4699999999998, 31.5243749999998);//N3
	glVertex2f(50.1299999999998, 31.9843749999998);//O3
	glVertex2f(47.3299999999998, 32.0243749999998);//P3
	glEnd();

	glBegin(GL_LINES);//Huruf P lurus
	glColor3f(1, 0.016, 0.016);
	glVertex2f(52.7299999999998, 25.2843749999998);//Q3
	glVertex2f(52.7299999999998, 31.5843749999998);//R3
	glEnd();

	glBegin(GL_LINES);//Huruf P lengkung
	glColor3f(1, 0.016, 0.016);
	glVertex2f(53.0499999999996, 28.4743749999999);//S3
	glVertex2f(55.8099999999996, 28.4943749999999);//T3
	glVertex2f(56.3099999999995, 29.0143749999999);//U3
	glVertex2f(56.3099999999995, 31.4943749999999);//V3
	glVertex2f(55.8499999999996, 32.0343749999999);//W3
	glVertex2f(53.2099999999996, 32.0743749999999);//Z3
	glEnd();

	glBegin(GL_POLYGON);//tanda Seru atas
	glColor3f(1, 0.016, 0.016);
	glVertex2f(58, 32);//A4
	glVertex2f(58, 30);//B4
	glVertex2f(58.2899999999995, 29.9743749999999);//C4
	glVertex2f(58.2699999999995, 27.7743749999999);//D4
	glVertex2f(58.2699999999995, 27.7743749999999);//D4
	glVertex2f(59.5099999999995, 27.7343749999999);//E4
	glVertex2f(59.5099999999995, 27.7343749999999);//E4
	glVertex2f(59.5699999999995, 29.8943749999999);//F4
	glVertex2f(59.8499999999995, 29.8943749999999);//G4
	glVertex2f(59.8099999999995, 31.9943749999999);//H4
	glVertex2f(59.4699999999995, 32.3343749999999);//I4
	glVertex2f(58.2899999999995, 32.3343749999999);//J4
	glEnd();

	glBegin(GL_POLYGON);//tanda Seru bawah
	glColor3f(1, 0.016, 0.016);
	glVertex2f(58.8699999999995, 26.5143749999999);//K4
	glVertex2f(59.5699999999995, 25.8743749999999);//L4
	glVertex2f(58.8499999999995, 25.2143749999999);//M4
	glVertex2f(58.2099999999995, 25.8343749999999);//N4
	glEnd();

	glBegin(GL_LINES);//Huruf T lurus atas
	glColor3f(1, 0.016, 0.016);
	glVertex2f(61.5099999999995, 32.0743749999999);//O4
	glVertex2f(66.2099999999995, 32.0743749999999);//P4
	glEnd();

	glBegin(GL_LINES);//Huruf T lurus bawah
	glColor3f(1, 0.016, 0.016);
	glVertex2f(63.7099999999995, 31.7943749999999);//Q4
	glVertex2f(63.6899999999995, 25.3743749999999);//R4
	glEnd();

    glPopMatrix();


    glPushMatrix();//Dokter
    glScaled(1,1,0);
    glTranslated(38,7,0);

    glLineWidth(8  );
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


    glPushMatrix();//Spacebar
    //glColor3f(0.094, 0.067, 0.369);
    glScaled(0.5,0.5,0);
    glTranslated(5,10,0);
    text(61.1050140834839, 32.8465056818181,"**PRESS SPACEBAR TO START**", GLUT_BITMAP_HELVETICA_18,0.094, 0.067, 0.369);
    glPopMatrix();


    glPushMatrix();//created by
    glTranslated(-34, -90, 0);
    text(66.111069078946, 95.6524342105263,"created by : Amiroh, Gavriel, Ratna, Ijul", GLUT_BITMAP_HELVETICA_18,1,1,1);
    glPopMatrix();

}
void dokterKeyboard(int key, int x, int y){
    //cek();
    if(GetAsyncKeyState(VK_RIGHT)){
        if (colliderDokter[1]<=85){
            horDokter=true;
            colliderDokter[0]+=0.5;
            colliderDokter[1]+=0.5;
            gerakDokter[0]+=0.5;
        }
    }
    if (GetAsyncKeyState(VK_LEFT)){
        if (colliderDokter[0]>=0){
            horDokter=false;
            colliderDokter[0]-=0.5;
            colliderDokter[1]-=0.5;
            gerakDokter[0]-=0.5;
        }

    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y){
    if (key==32 && !playStatus){
        if(imunitas<=0){
           gameOverStatus=false;
            imunitas=30;
            scorePoin=0;
            status=true;
            mode1Status=true;
            bool statusDeleteVirus=true;
        }
        else{
            playStatus=true;
            mode1Status=true;

        }



    }
    if (key==27){
        exit(0);
    }
}
void collObat(){
    glBegin(GL_QUADS); //Badan obat1
	glColor3f(0.804, 0.804, 0.804);
	glVertex2f(colliderObat[0],colliderObat[2]);
	glVertex2f(colliderObat[0],colliderObat[3]);
	glVertex2f(colliderObat[1],colliderObat[3]);
	glVertex2f(colliderObat[1],colliderObat[2]);
	glEnd();
}

void collDokter(){
    glBegin(GL_QUADS); //Badan obat1
	glColor3f(0.804, 0.804, 0.804);
	glVertex2f(colliderDokter[0],colliderDokter[2]);
	glVertex2f(colliderDokter[0],colliderDokter[3]);
	glVertex2f(colliderDokter[1],colliderDokter[3]);
	glVertex2f(colliderDokter[1],colliderDokter[2]);
	glEnd();
}

void dokterObject(){
    glPushMatrix();
    glTranslated(gerakDokter[0],0,0);
    glScaled(1.1,1.1,0);

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

void timerDokter(int){
    glutTimerFunc(1000/30,timerDokter,0);
    if (playStatus){
        dokterObject();
        glutPostRedisplay();
        if (horDokter){
            colliderDokter[0]+=0.5;
            colliderDokter[1]+=0.5;
            gerakDokter[0]+=0.5;
        }
        else{
            colliderDokter[0]-=0.5;
            colliderDokter[1]-=0.5;
            gerakDokter[0]-=0.5;
        }

        if (colliderDokter[1]>=85){
            horDokter=false;
        }
        if (colliderDokter[0]<=0){
            horDokter=true;
        }
     }
}

void obatObject(){
    glPushMatrix();
    glTranslated(gerakObat[0],gerakObat[1],0);
    glTranslated(obatAwal[0],obatAwal[1],0);

    glBegin(GL_POLYGON); //Badan obat1
	glColor3f(0.804, 0.804, 0.804);
	glVertex2f(0,0);
	glVertex2f(5,0);
	glVertex2f(5,4);
	glVertex2f(0,4);
	glEnd();

	glBegin(GL_POLYGON); //badan obat2
	glColor3f(0.855, 0.855, 0.855);
	glVertex2f(4,4);
	glVertex2f(4,5);
	glVertex2f(1,5);
	glVertex2f(1,4);
	glEnd();

	glBegin(GL_POLYGON); //badan obat3
	glColor3f(1, 1, 1);
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

	glLineWidth(5);//outline obat
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0,0);//A
	glVertex2f(0,4);//D
	glVertex2f(1,4);//H
	glVertex2f(1,5);//G
	glVertex2f(1.59,5);//L
	glVertex2f(1.61,5.96);//K
	glVertex2f(3.32337,5.98376);//J
	glVertex2f(3.32,5);//I
	glVertex2f(4,5);//F
	glVertex2f(4,4);//E
	glVertex2f(5,4);//C
	glVertex2f(5,0);//B
	glEnd();
	glPopMatrix();


}

void timerObat(int){
    obatObject();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerObat,0);
    if (colliderObat[3]>=-0){
        colliderObat[2]-=1;
        colliderObat[3]-=1;
        gerakObat[1]-=1;
    }
    else{
        colliderObat[2]=45;
        colliderObat[3]=52;
        int x=rand() % 80+1;
        colliderObat[0]=x;
        colliderObat[1]=x+5;
        obatAwal[0]=x;
        gerakObat[1]=0;

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

void virusDisplay(int sumOfVirus){
        for(int i = 0; i < sumOfVirus; i++) {
        arrayVirus[i].movement();

    }
    }

void virusRand(int a){
    if (status){
        srand(time(NULL));
        for(int i = 0; i < a; i++) {
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

void deleteVirus(){
    if (statusDeleteVirus){
    for(int i = 0; i < 10; i++) {
        arrayVirus[i].posisiAwal[0]=1000;
        arrayVirus[i].posisiAwal[1]=1000;
        arrayVirus[i].colliderVirus[0]=1000;
        arrayVirus[i].colliderVirus[1]=1000+5;
        arrayVirus[i].colliderVirus[2]=1000;
        arrayVirus[i].colliderVirus[3]=1000+5;
        arrayVirus[i].gerakVirus[0]=0;
        arrayVirus[i].gerakVirus[1]=0;
    }
    }
}

void timerMode(int){
    glutTimerFunc(15000,timerMode,0);
    if (playStatus){
        if (mode1Status){
            statusDeleteVirus=true;
            //glutTimerFunc(5000,timerMode,0);
            mode1Status=false;
            if(statusDeleteVirus){
                status=true;
            }
            statusDeleteVirus=true;

        }
        else {
            //glutTimerFunc(5000,timerMode,0);
            statusDeleteVirus=true;
            mode1Status=true;
            if(statusDeleteVirus){
                status=true;
            }

        }
    }
}

void timerScore(int){
    glutTimerFunc(1000,timerScore,0);
    if (playStatus){
            scorePoin+=1;
    }
}


//===============================SCORE==============================
void collisionDokterObat(){
    bool collDokterObatX=colliderObat[1]<=colliderDokter[1]+5 && colliderObat[0]>=colliderDokter[0]-5;
    bool collDokterObatY=colliderObat[2]<=colliderDokter[3];
    if (colliderObat[2]==45){
        scoreStatus=true;
    }
    if (collDokterObatX && collDokterObatY && scoreStatus ){
        imunitas+=1;

        cout << "imun nambah: " << imunitas << "\n";
        cout << "status 2 " << scoreStatus << "\n";
        scoreStatus=false;

    }
}

class CollisionVirus{
public:
    int a;
    bool scoreStatusVirus=true;
    bool collDokterVirusX;
    bool collDokterVirusY;

    CollisionVirus(int a){
        //int i=0;
        bool collDokterVirusX=arrayVirus[a].colliderVirus[1]<=colliderDokter[1]+5 && arrayVirus[a].colliderVirus[0]>=colliderDokter[0]-5;
        bool collDokterVirusY=arrayVirus[a].colliderVirus[2]<=colliderDokter[3];
        bool scoreStatusVirus=arrayVirus[a].colliderVirus[1]>=colliderDokter[1]+5 || arrayVirus[a].colliderVirus[0]<=colliderDokter[0]-5 ;

        if (collDokterVirusX && collDokterVirusY && scoreStatusVirus){
            imunitas-=1;

            //cout << "imun berkurang: " << imunitas << "\n";
            //cout << "status 2 " << scoreStatusVirus << "\n";
            scoreStatusVirus=false;
        }
}
};

void collisionDokterVirus(){
   // for(int a = 0; a < 20; a++) {
        CollisionVirus(0);
        CollisionVirus(1);
        CollisionVirus(2);
        CollisionVirus(3);
        CollisionVirus(4);
        CollisionVirus(5);
        CollisionVirus(6);
        CollisionVirus(7);
        CollisionVirus(8);
        CollisionVirus(9);
        //CollisionVirus(10);
        //CollisionVirus(11);

    //}
}

void score(){
    collisionDokterObat();
    collisionDokterVirus();
}

void kotakDarah (){
    glPushMatrix();
    glTranslated(0,-1.5,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(75, 45.53);
    glVertex2f(75, 43.6);
    glVertex2f(85, 43.6);
    glVertex2f(85, 45.53);
    glEnd();
    text(76, 44.3, "Imunitas", GLUT_BITMAP_TIMES_ROMAN_24,1,1,1);
    glPopMatrix();

}

void poinDarah(int x){
    //x=-x;
    glPushMatrix();
    glTranslated(x,0,0);
    glTranslated(0,-1.5,0);
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.678, 0, 0.024);
    glVertex2f(85, 43);
    glEnd();
    glPopMatrix();
}

void updatePoin(){
    for(int i = 1; i < imunitas+1; i++) {
        poinDarah(-i);
}
}
void scoreKamu (){
    glPushMatrix();
    glTranslated(0,-0.7,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(75, 41.45);
    glVertex2f(85, 41.45);
    glVertex2f(85, 39.8);
    glVertex2f(75, 39.8);
    glEnd();
    text(76, 40.5, "Score Kamu", GLUT_BITMAP_TIMES_ROMAN_24,1,1,1);
    glPopMatrix();
}

void tempatScore (){
    glPushMatrix();
    glTranslated(0,-0.7,0);
    glBegin(GL_POLYGON);
    glColor3f(0.302, 0.302, 0.302);
    glVertex2f(76.77, 39.8);
    glVertex2f(85, 39.8);
    glVertex2f(85, 37.07);
    glVertex2f(76.77, 37.07);
    glEnd();
    char poin[1000];
    sprintf(poin,"%d", scorePoin);
    text(80, 38, poin, GLUT_BITMAP_TIMES_ROMAN_24,1,1,1);

    glPopMatrix();
}



void background1(){
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

void objectOrang (int x,int y){
    glPushMatrix();
    glTranslated(x,y,0);
    glBegin(GL_POLYGON); //tangan kiri
    glColor3f(0.6,0.4,0.2);
    glVertex2f(16.66,23.26);
    glVertex2f(16.66,19.4);
    glVertex2f(18.02,19.4);
    glVertex2f(18.02,23.26);
    glEnd();

    glBegin(GL_POLYGON); //tangan kanan
    glColor3f(0.6,0.4,0.2);
    glVertex2f(22.41,23.26);
    glVertex2f(22.41,19.4);
    glVertex2f(21.03,19.4);
    glVertex2f(21.03,23.26);
    glEnd();

    glBegin(GL_POLYGON); //badan
    glColor3f(0.6,0.6,0.6);
    glVertex2f(18.03,15.71);
    glVertex2f(21.02,15.71);
    glVertex2f(21.03,23.26);
    glVertex2f(18.03,23.26);
    glEnd();

    glBegin(GL_POLYGON); //kepala
    glColor3f(0.6,0.4,0.2);
    glVertex2f(18.57,23.26);
    glVertex2f(18.57,25.15);
    glVertex2f(20.47,25.15);
    glVertex2f(20.47,23.26);
    glEnd();

    glBegin(GL_POLYGON); //mulut
    glColor3f(1,1,1);
    glVertex2f(18.88,23.85);
    glVertex2f(20.21,23.85);
    glVertex2f(20.21,23.6);
    glVertex2f(18.88,23.6);
    glEnd();

    glBegin(GL_POLYGON); //mata kiri
    glColor3f(0,0,0);
    glVertex2f(18.94,24.82);
    glVertex2f(19.17,24.82);
    glVertex2f(19.17,24.57);
    glVertex2f(18.94,24.57);
    glEnd();

    glBegin(GL_POLYGON); //mata kanan
    glColor3f(0,0,0);
    glVertex2f(19.88,24.82);
    glVertex2f(20.1,24.82);
    glVertex2f(20.1,24.57);
    glVertex2f(19.88,24.57);
    glEnd();
    glPopMatrix();
}

void background2(){
    glBegin(GL_POLYGON); //langit
	glColor3f(0.137, 0.161, 0.302);
	glVertex2f(85, 15.2);
	glVertex2f(0, 15.2);
	glVertex2f(0, 45.53);
	glVertex2f(85, 45.53);
	glEnd();

	glBegin(GL_POLYGON); //rumput hijau
	glColor3f(0,0.8,0.4);
	glVertex2f(0, 7.47);
	glVertex2f(85, 7.47);
	glVertex2f(85, 15.2);
	glVertex2f(0, 15.2);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat muda
	glColor3f(0.58, 0.467, 0.294);
	glVertex2f(85, 3.46);
	glVertex2f(0, 3.46);
	glVertex2f(0, 7.47);
	glVertex2f(85, 7.47);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat tua
	glColor3f(0.467, 0.373, 0.239);
	glVertex2f(0, 0);
	glVertex2f(85, 0);
	glVertex2f(85, 3.46);
	glVertex2f(0, 3.46);
	glEnd();

    glBegin(GL_POLYGON); //bulan
    glColor3f(0.722, 0.722, 0.137);
	glVertex2f(19.72, 43.79);//Q3
	glVertex2f(20.28, 43.65);//R3
	glVertex2f(20.73, 43.35);//S3
	glVertex2f(21.12, 43.05);//T3
	glVertex2f(21.51, 42.66);//U3
	glVertex2f(21.84, 42.3);//V3
    glVertex2f(22, 42);//W3
	glVertex2f(22.2, 41.4);//Z3
	glVertex2f(22.44, 41.01);//A4
	glVertex2f(22.53, 40.56);//B4
	glVertex2f(22.53, 40.05);//C4
	glVertex2f(22.47, 39.61);//D4
	glVertex2f(22.41, 39.13);//E4
	glVertex2f(22.23, 38.59);//F4
    glVertex2f(22, 38);//G4
	glVertex2f(21.57145,37.66144);//H4
	glVertex2f(21.12268,37.30243);//I4
	glVertex2f(20.61408,36.82374);//J4
	glVertex2f(20.01572,36.58439);//K4
	glVertex2f(19.26776,36.4348);//L4
	glVertex2f(18.43006,36.4348);//M4
	glVertex2f(17.74194,36.58439);//N4
    glVertex2f(17.11366,36.7639);//O4
	glVertex2f(16.39563,37.12292);//P4
	glVertex2f(15.79727,37.63152);//Q4
	glVertex2f(15.44267,38.37811);//R4
	glVertex2f(15.10916,39.00775);//S4
	glVertex2f(14.95957,39.78562);//T4
	glVertex2f(14.98948,40.65325);//U4
	glVertex2f(15.28866,41.58071);//V4
    glVertex2f(15.64768,42.26882);//W4
	glVertex2f(16.12913,42.78423);//Z4
	glVertex2f(16.5442,43.16737);//A5
	glVertex2f(16.9433,43.4228);//B5
	glVertex2f(17.47012,43.64629);//C5
	glVertex2f(17.94905,43.78997);//D5

	glEnd();
	glPointSize(5);
    glBegin(GL_POINTS); //bintang
 	glVertex2f(25,43.78997);
	glVertex2f(25,43.7);
	glVertex2f(25,43.7);
	glVertex2f(20,40);
	glVertex2f(15,36);
	glVertex2f(10,43.7);
	glVertex2f(13,38);
	glVertex2f(21,29);
	glVertex2f(12,18);
	glVertex2f(11,19);
	glVertex2f(10,21);
	glVertex2f(15,36);
	glVertex2f(30,42.5);
	glVertex2f(35.43,41.3);
	glVertex2f(48,43.7);
	glVertex2f(49,41.2);
	glVertex2f(43,40.1);
	glVertex2f(55,40.1);
	glVertex2f(60,37.7);
	glVertex2f(10,37.7);
	glVertex2f(5,39.7);
	glVertex2f(70,35.7);
 	glEnd();
    glPopMatrix();

    glBegin(GL_POLYGON); //daun pohon
    glColor3f(0,0.6,0.2);
    glVertex2f(62.77,20.8);
    glVertex2f(68.48,35.68);
    glVertex2f(74.19,20.78);
    glEnd();

    glBegin(GL_POLYGON); //tangkai pohon
    glColor3f(0.467, 0.373, 0.239);
    glVertex2f(67.64,15.2);
    glVertex2f(69.31,15.2);
    glVertex2f(69.31,20.78);
    glVertex2f(67.63,20.79);
    glEnd();

//CAFE
    glBegin(GL_POLYGON); //lantai
    glColor3f(0.502,0.502,0.502);
    glVertex2f(60.28,15.2);
    glVertex2f(60.28,13.61);
    glVertex2f(26.15,13.61);
    glVertex2f(26.15,15.2);
    glEnd();

    glBegin(GL_POLYGON); //badan bangunan
    glColor3f(0,0.667,0.514);
    glVertex2f(28.04,25.38);
    glVertex2f(58.16,25.38);
    glVertex2f(58.16,15.2);
    glVertex2f(28.04,15.2);
    glEnd();

    glBegin(GL_POLYGON); //atap1
    glColor3f(1,0.396,0.369);
    glVertex2f(26.17,25.39);
    glVertex2f(27.87,28.43);
    glVertex2f(58.16,28.43);
    glVertex2f(59.84,25.4);
    glEnd();

    glBegin(GL_POLYGON); //atap2
    glColor3f(0.4,0.392,0.294);
    glVertex2f(27.87,28.43);
    glVertex2f(58.16,28.43);
    glVertex2f(58.16,31.71);
    glVertex2f(27.87,31.71);
    glEnd();

    glBegin(GL_POLYGON); //atap3
    glColor3f(0.541,0.502,0.396);
    glVertex2f(34.67,31.71);
    glVertex2f(38.99,37.59);
    glVertex2f(47.65,37.6);
    glVertex2f(51.99,31.72);
    glEnd();

    glBegin(GL_POLYGON); //pintu cafe
    glColor3f(0.545,0.902,0.984);
    glVertex2f(41.4,23.6);
    glVertex2f(44.5,23.6);
    glVertex2f(44.49,15.2);
    glVertex2f(41.4,15.2);
    glEnd();

    glBegin(GL_POLYGON); //jendela kiri1
    glColor3f(0.545,0.902,0.984);
    glVertex2f(32.66,23.58);
    glVertex2f(35.66,23.58);
    glVertex2f(35.66,19.23);
    glVertex2f(32.66,19.23);
    glEnd();

    glBegin(GL_POLYGON); //jendelakiri2
    glColor3f(0.545,0.902,0.984);
    glVertex2f(37.07,23.6);
    glVertex2f(40.05,23.6);
    glVertex2f(40.05,19.23);
    glVertex2f(37.07,19.23);
    glEnd();

    glBegin(GL_POLYGON); //jendela kanan1
    glColor3f(0.545,0.902,0.984);
    glVertex2f(45.42,23.57);
    glVertex2f(48.41,23.57);
    glVertex2f(48.41,19.23);
    glVertex2f(45.42,19.23);
    glEnd();

    glBegin(GL_POLYGON); //jendela kanan2
    glColor3f(0.545,0.902,0.984);
    glVertex2f(49.45,23.6);
    glVertex2f(52.44,23.6);
    glVertex2f(52.44,19.23);
    glVertex2f(49.45,19.23);
    glEnd();
    objectOrang(0,-3);
    objectOrang(6,-2);
    objectOrang(-12,-1);
    objectOrang(-6,-4);
    objectOrang(54,-10);
    objectOrang(60,-8);
    objectOrang(42,-10);
    objectOrang(48,-6);
    objectOrang(25,-5);
    objectOrang(31,-3);
    objectOrang(19,-4);
}

void finalScore(){
    if (imunitas>0){
        int a = scorePoin;
        sprintf(finalPoin,"%d", a);
    }
}

void gameOver() {
    glPushMatrix();
    glTranslated(0, 5, 0);
    glLineWidth(15);
    glBegin(GL_LINES); //huruf G
	glColor3f(1,0,0);
	glVertex2f(22.5775965827964,28.5743484549706); //G
	glVertex2f(18.6717757575239,28.5743484549706); //H
	glVertex2f(18.6193486323525,21.2345509309685); //I
	glVertex2f(22.5513830202107,21.1296966806256); //J
	glVertex2f(22.5513830202107,25.0879446310696); //K
	glVertex2f(20.4805115759387,25.0879446310696); //L
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(18.6717757575239,28.5743484549706);
    glVertex2f(18.6193486323525,21.2345509309685); //I
	glVertex2f(22.5513830202107,21.1296966806256); //J
	glVertex2f(22.5513830202107,25.0879446310696); //K
	glEnd();

	glBegin(GL_LINES);//huruf A
	glColor3f(1, 0, 0);
	glVertex2f(24.491186651554,21.0772695554542);//M
	glVertex2f(24.4649730889683,23.1219274371404);//N
	glVertex2f(25.0154579032685,23.1219274371404); //O
	glVertex2f(24.963030778097,26.1364871344984);//P
	glVertex2f(25.5135155923972,26.084060009327);//Q
	glVertex2f(25.4610884672257,28.5481348923848);//R
	glVertex2f(27.4271056611548,28.5481348923848);//S
	glVertex2f(27.4795327863263,26.084060009327);//T
	glVertex2f(28,26);//U
	glVertex2f(28.0038040380407,23.1481409997262);//V
	glVertex2f(28.3970074768265,23.069500311969);//W
	glVertex2f(28.4232210394123,21.0510559928684);//Z
    glEnd();
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2f(24.4649730889683,23.1219274371404);//N
    glVertex2f(28.3970074768265,23.069500311969);//W
    glVertex2f(25.4610884672257,28.5481348923848);//R
    glVertex2f(27.4271056611548,28.5481348923848);//S
    glVertex2f(24.963030778097,26.1364871344984);//P
	glVertex2f(25.5135155923972,26.084060009327);//Q
	glVertex2f(27.4795327863263,26.084060009327);//T
	glVertex2f(28,26);//U
    glEnd();

	glBegin(GL_LINES); //huruf M
	glColor3f(1, 0, 0);
	glVertex2f(29.8649669816269,21.1034831180399);//A1
	glVertex2f(29.8911805442127,28.4957077672134);//B1
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,0,0);
    glVertex2f(32.8533131163992,28.4957077672134);//E1
	glVertex2f(32.8533131163992,21.0510559928684);//F1
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(35.8940863763429,28.5743484549706);//C1
	glVertex2f(35.8154456885857,21.0510559928684);//D1
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(29.8911805442127,28.4957077672134);//B1
	glVertex2f(35.8940863763429,28.5743484549706);//C1
	glEnd();


	glBegin(GL_LINES); //Huruf E
	glColor3f(1, 0, 0);
	glVertex2f(41.2590756768552,28.545423893915);//G1
	glVertex2f(38.2267547772029,28.545423893915);//H1
	glVertex2f(38.2628538355321,21.1812159947594);//I1
	glVertex2f(41.2590756768552,21.109017878101);//J1
	glVertex2f(38.2989528938613,25.0438152359832);//K1
	glVertex2f(41.2951747351844,25.007716177654);//L1
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex2f(38.2267547772029,28.545423893915);//H1
    glVertex2f(38.2628538355321,21.1812159947594);//I1
    glEnd();

	glBegin(GL_LINES);//Huruf O
	glColor3f(1, 0, 0);
	glVertex2f(43.5694154099236,28.1483342522939);//M1
	glVertex2f(43.6055144682528,21.5061075197221);//N1
	glVertex2f(48.557990670051,21.5538440338011);//Q1
	glVertex2f(48.5550439139275,28.1371853464544);//R1
	glEnd();
	glBegin(GL_LINES);//Huruf O
	glColor3f(1, 0, 0);
	glVertex2f(44.0748022265323,21.0368197614426);//O1
	glVertex2f(48.117896759402,21.0368197614426);//P1
	glVertex2f(48.021782641925,28.54925087482);//S1
	glVertex2f(44.1070491264353,28.5235791239323);//T1
	glEnd();


	glBegin(GL_LINES);//Huruf v
	glColor3f(1, 0, 0);
	glVertex2f(49.994478166364,28.7035848185276);//U1
	glVertex2f(50,24);//V1
	glVertex2f(50.5614075066036,24.0421401781123);//W1
	glVertex2f(50.5614075066036,23.5119623608881);//Z1
	glVertex2f(51.0915853238278,23.6494158690573);//A2
	glVertex2f(51,23);//B2
	glVertex2f(51.5628544946937,23.0603294054749);//C2
	glVertex2f(51.5235820637882,22.5694240191562);//D2
	glVertex2f(52.0537598810124,22.5301515882507);//E2
	glVertex2f(52.0144874501069,21.6661581083298);//F2
	glVertex2f(52.9766620072915,21.5483408156133);//G2
	glVertex2f(52.9570257918388,22.5890602346089);//H2
	glVertex2f(53.5068398245157,22.5694240191562);//I2
	glVertex2f(53.4479311781575,23.1977829136441);//J2
	glVertex2f(53.9977452108344,23.1585104827386);//K2
	glVertex2f(53.8995641335707,23.6494158690573);//L2
    glVertex2f(54.4167101970082,23.5664176698702);//M2
	glVertex2f(54.4026999404128,24.0847971638997);//N2
	glVertex2f(55,24);//O2
	glVertex2f(54.9047437298755,28.7349598427007);//P2
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(50,24);//V1
	glVertex2f(50.5614075066036,24.0421401781123);//W1
	glVertex2f(50.5614075066036,23.5119623608881);//Z1
	glVertex2f(51.0915853238278,23.6494158690573);//A2
	glVertex2f(51,23);//B2
	glVertex2f(51.5628544946937,23.0603294054749);//C2
	glVertex2f(51.5235820637882,22.5694240191562);//D2
	glVertex2f(52.0537598810124,22.5301515882507);//E2
	glVertex2f(52.0144874501069,21.6661581083298);//F2
	glVertex2f(52.9766620072915,21.5483408156133);//G2
	glVertex2f(52.9570257918388,22.5890602346089);//H2
	glVertex2f(53.5068398245157,22.5694240191562);//I2
	glVertex2f(53.4479311781575,23.1977829136441);//J2
	glVertex2f(53.9977452108344,23.1585104827386);//K2
	glVertex2f(53.8995641335707,23.6494158690573);//L2
    glVertex2f(54.4167101970082,23.5664176698702);//M2
	glVertex2f(54.4026999404128,24.0847971638997);//N2
	glVertex2f(55,24);//O2
	glEnd();


	glBegin(GL_LINES);//huruf E
	glColor3f(1, 0, 0);
	glVertex2f(59.5353452810274,28.5234095180288);//Q2
	glVertex2f(56.2680680444279,28.4999039263985);//R2
	glVertex2f(56.4796183690998,24.9740651818667);//U2
	glVertex2f(59.3708061396159,24.9740651818667);//V2
	glVertex2f(56.4091015942091,21.0721369712514);//S2
	glVertex2f(59.3943117312461,21.0721369712514);//T2
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(56.2680680444279,28.4999039263985);//R2
	glVertex2f(56.4091015942091,21.0721369712514);//S2
	glEnd();

	glBegin(GL_LINES);//huruf R
	glColor3f(1, 0, 0);
	glVertex2f(60.8159433978148,28.5911781528008);//Z2
	glVertex2f(60.8544840552775,21.0757499475793);//W2
	glVertex2f(64.7470904590076,28.5719078240694);//A3
	glVertex2f(64.7856311164702,25.4308442408615);//B3
	glEnd();
    glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex2f(60.8159433978148,28.5911781528008);//Z2
	glVertex2f(64.7470904590076,28.5719078240694);//A3
	glVertex2f(64.7856311164702,25.4308442408615);//B3
	glVertex2f(60.9315653702028,25.5079255557868);//C3
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(61.8180004918443,25.4886552270555);//D3
	glVertex2f(61.8372708205757,24.5058684617573);//E3
	glVertex2f(62.2997587101278,24.54440911922);//F3
	glVertex2f(62.3036977588554,24.0477445358396);//G3
	glVertex2f(62.8020131804195,24.0208085671064);//H3
	glVertex2f(62.8154811647861,23.5494291142754);//I3
	glVertex2f(63.3003286019836,23.5224931455422);//J3
	glVertex2f(63.2733926332504,23.0376457083447);//K3
	glVertex2f(63.7851760391811,23.0376457083447);//L3
	glVertex2f(63.7582400704479,22.593202224247);//M3
	glVertex2f(64.2834914607452,22.5662662555138);//N3
	glVertex2f(64.2430875076454,21.5831033967522);//O3
	glVertex2f(64.7683388979427,21.5831033967522);//P3
	glVertex2f(64.7683388979427,21.0982559595547);//Q3
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(61.8372708205757,24.5058684617573);//E3
	glVertex2f(62.2997587101278,24.54440911922);//F3
	glVertex2f(62.3036977588554,24.0477445358396);//G3
	glVertex2f(62.8020131804195,24.0208085671064);//H3
	glVertex2f(62.8154811647861,23.5494291142754);//I3
	glVertex2f(63.3003286019836,23.5224931455422);//J3
	glVertex2f(63.2733926332504,23.0376457083447);//K3
	glVertex2f(63.7851760391811,23.0376457083447);//L3
	glVertex2f(63.7582400704479,22.593202224247);//M3
	glVertex2f(64.2834914607452,22.5662662555138);//N3
	glVertex2f(64.2430875076454,21.5831033967522);//O3
	glVertex2f(64.7683388979427,21.5831033967522);//P3
	glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-22, -15, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.576, 0.463, 0.153);
    glVertex2f(56.8688312322439, 36.6002343749999);
    glVertex2f(71.9872971413351, 36.6002343749999);
    glVertex2f(71.9872971413351, 29.5587571022725);
    glVertex2f(56.8688312322439, 29.5587571022725);
    glEnd();
    glColor3f(1,1,1);
    text(62.5, 35,"Score :",GLUT_BITMAP_TIMES_ROMAN_24,1,1,1);
    glPopMatrix();


    text(41.7, 17, finalPoin, GLUT_BITMAP_TIMES_ROMAN_24,1,1,1);
    text(38.5,10,"Press esc to exit",GLUT_BITMAP_HELVETICA_18,1,1,1);
    text(36.5,8,"Press spacebar to menu",GLUT_BITMAP_HELVETICA_18,1,1,1);
}

void mode1(){
    if(mode1Status && !gameOverStatus){
       background1();
        kotakDarah();
        updatePoin();
        scoreKamu();
        tempatScore();
        deleteVirus();
        virusRand(5);
        virusDisplay(5);
        dokterObject();
        obatObject();
        score();
        status=false; //untuk timer random virus
        statusDeleteVirus=false;
    }

}

void mode2(){
    if(!mode1Status && !gameOverStatus){
        background2();
        kotakDarah();
        tempatScore();
        scoreKamu();
        updatePoin();
        deleteVirus();
        virusRand(10);
        virusDisplay(10);
        dokterObject();
        obatObject();
        score();
        status=false; //untuk timer virus
        statusDeleteVirus=false;
    }
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    if (!playStatus && !gameOverStatus){
        menu1();
    }
    if(playStatus && imunitas>0){
            cout << scorePoin << "\n";
        mode1();
        mode2();
        finalScore();
        char a[1000];
        //sprintf(a,"%d",imunitas);
        //text(30, 30,a, GLUT_BITMAP_TIMES_ROMAN_24,0,0,0);
    }
    if(imunitas<=0){

        statusDeleteVirus=true;
        deleteVirus();
        playStatus=false;
        gameOverStatus=true;
        gameOver();
    }
    glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Awas Kopit");
	glutDisplayFunc(displayMe);
	glutSpecialFunc(dokterKeyboard);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(1000,timerScore,0);
	glutTimerFunc(0,timerMode,0);
	glutTimerFunc(0,timerObat,0);
	glutTimerFunc(0,timerDokter,0);
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

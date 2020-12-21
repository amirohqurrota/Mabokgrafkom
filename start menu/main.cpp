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


void background() {
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

}



void judul() {
    glPushMatrix();
    glTranslated(21, 40, 0);
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
}

void dokter() {
    glPushMatrix();
    glScaled(1.3,2,0);
    glTranslated(45.5,9.3,0);

    glLineWidth(70);
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
}

void drawText(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void menu() {
    glPushMatrix();

    glColor3f(0.094, 0.067, 0.369);
    glTranslated(-11,17,0);
    drawText(61.1050140834839, 32.8465056818181,"**PRESS SPACEBAR TO START**");

    glPopMatrix();
}

void drawText2(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void createdby() {
    glPushMatrix();
    glTranslated(-17, -83, 0);
    glColor3f(1,1,1);
    drawText2(66.111069078946, 95.6524342105263,"created by : Amiroh, Gavriel, Ratna, Ijul");
    glPopMatrix();
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    judul();
    menu();
    dokter();
    createdby();
	glutSwapBuffers();
}

void init(){ //merubah background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0); //buat ganti warna yang putih di atas
    glColor3f(0.0,0.0,0.0);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("start menu ");
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 130, 0, 130);
	init();
	glutMainLoop();
	return 0;
}


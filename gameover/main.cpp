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

#include <cstdlib>
#include <ctime>


void background() {
    glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 36);
	glVertex2f(0, 107);
	glVertex2f(149, 107);
	glVertex2f(149, 36);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 36);
	glVertex2f(0, 17);
	glVertex2f(149, 17);
	glVertex2f(149, 36);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 18);
	glVertex2f(0, 8);
	glVertex2f(150, 8);
	glVertex2f(150, 18);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(0, 8);
	glVertex2f(0, 0);
	glVertex2f(150, 0);
	glVertex2f(150, 8);
	glEnd();

}



void over() {
    glPushMatrix();
    glTranslated(21, 40, 0);
    glLineWidth(10);


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
}

void drawText(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void score() {
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.576, 0.463, 0.153);
    glVertex2f(56.8688312322439, 36.6002343749999);
    glVertex2f(71.9872971413351, 36.6002343749999);
    glVertex2f(71.8837460049714, 29.5587571022725);
    glVertex2f(56.8688312322439, 29.4552059659088);
    glEnd();
    glColor3f(1,1,1);
    drawText(61.1050140834839, 32.8465056818181,"Score :");

    glPopMatrix();
}

void drawText2(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void exit() {
    glPushMatrix();
    glTranslated(-17, -83, 0);
    glColor3f(1,1,1);
    drawText2(75,100,"Press esc to exit");
    glPopMatrix();
}

void drawText3(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}

void menu() {
    glPushMatrix();
    glTranslated(-17, -83, 0);
    glColor3f(1,1,1);
    drawText2(72,97,"Press spacebar to menu");
    glPopMatrix();
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    background();
    over();
    score();
    exit();
    menu();
	glutSwapBuffers();
}

void init(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Game Over");
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 130, 0, 130);
	init();
	glutMainLoop();
	return 0;
}

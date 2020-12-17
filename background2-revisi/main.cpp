#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void background2(){
    glBegin(GL_POLYGON); //langit
	glColor3f(0.639, 0.2, 1);
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
    glColor3f(0.702, 0.702, 0.702);
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

//OBJEK ORANG
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
}

void kotakDarah (){
    glPushMatrix();
    glTranslated(0,-1.5,0);
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex2f(78.29, 45.53);
    glVertex2f(78.29, 44);
    glVertex2f(85, 44);
    glVertex2f(85, 45.53);
    glEnd();

    glBegin(GL_POLYGON); //outline
    glVertex2f(70.4, 44);
    glVertex2f(85, 44);
    glVertex2f(85, 42);
    glVertex2f(70.4, 42);
    glEnd();
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

void updatePoin(int poin){
    for(int i = 1; i < poin+1; i++) {
        poinDarah(-i);
}
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    background2();
    kotakDarah();
    updatePoin(25);
	glutSwapBuffers();
}

void init(){ //merubah background
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
	glutCreateWindow("background");
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 85 ,0, 45);
	init();
	glutMainLoop();
	return 0;
}

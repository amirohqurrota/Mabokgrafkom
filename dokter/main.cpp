#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);


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
	glutCreateWindow("medis");
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 85, 0, 45);
	init();
	glutMainLoop();
	return 0;
}


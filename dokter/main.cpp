#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON); //APD luar
	glColor3f(0.8f, 0.8f, 0.9f);
	glVertex2f(1.66,7.92);//A
	glVertex2f(0.84,7.04);//B
	glVertex2f(0.42,6.12);//C
	glVertex2f(0.4,4.94);//D
	glVertex2f(0.44,3.8);//E
	glVertex2f(1.04,2.82);//F
	glVertex2f(2,2);//G
	glVertex2f(4,2);//O
	glVertex2f(4.84,2.8);//N
	glVertex2f(5.64,3.84);//M
	glVertex2f(5.72,4.98);//L
	glVertex2f(5.72,6.1);//K
	glVertex2f(5.32,7.04);//J
	glVertex2f(4.62,7.92);//I
	glVertex2f(3.12,8.32);//H
	glEnd();

	glBegin(GL_POLYGON);//Leher
    glColor3f(0.8f, 0.8f, 0.9f);
	glVertex2f(2,2);//G
	glVertex2f(4,2);//O
	glVertex2f(6,0);//Z
	glVertex2f(0,0);//W
	glEnd();

    glBegin(GL_POLYGON);//atas kacamata
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
	glVertex2f(2.14,7);//R
	glVertex2f(4,7);//S
	glVertex2f(4.84,5.9);//T
	glVertex2f(1.16,5.92);//Q
	glEnd();

	glBegin(GL_POLYGON);//Masker
	glColor3f(0.8f, 0.9f, 0.9f);
	glVertex2f(2.98,4.54);//V
	glVertex2f(4.9,3.58);//U
	glVertex2f(4,2);//O
	glVertex2f(2,2);//G
	glVertex2f(1.12,3.64);//P
    glEnd();

    glBegin(GL_POLYGON);//Kacamata
    glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
    glVertex2f(2.98,4.54);//V
    glVertex2f(4.9,3.58);//U
    glVertex2f(4.84,5.9);//T
    glVertex2f(1.16,5.92);//Q
    glVertex2f(1.12,3.64);//P
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline Kacamata
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(2.98,4.54);//V
    glVertex2f(4.9,3.58);//U
    glVertex2f(4.84,5.9);//T
    glVertex2f(1.16,5.92);//Q
    glVertex2f(1.12,3.64);//P
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline Atas Kacamata
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(2.14,7);//R
	glVertex2f(4,7);//S
	glVertex2f(4.84,5.9);//T
	glVertex2f(1.16,5.92);//Q
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline APD + Leher
    glColor3f(0.2f, 0.3f, 0.4f);
    glVertex2f(0,0);//W
    glVertex2f(2,2);//G
    glVertex2f(1.04,2.82);//F
    glVertex2f(0.44,3.8);//E
    glVertex2f(0.4,4.94);//D
    glVertex2f(0.42,6.12);//C
    glVertex2f(0.84,7.04);//B
    glVertex2f(1.66,7.92);//A
	glVertex2f(3.12,8.32);//H
	glVertex2f(4.62,7.92);//I
	glVertex2f(5.32,7.04);//J
	glVertex2f(5.72,6.1);//K
	glVertex2f(5.72,4.98);//L
	glVertex2f(5.64,3.84);//M
	glVertex2f(4.84,2.8);//N
	glVertex2f(4,2);//O
	glVertex2f(6,0);//Z
	glVertex2f(0,0);//W
	glEnd();

	glBegin(GL_LINE_LOOP);//Outline Masker
    glColor3f(0.2f, 0.3f, 0.4f);
	glVertex2f(2.98,4.54);//V
	glVertex2f(4.9,3.58);//U
	glVertex2f(4,2);//O
	glVertex2f(2,2);//G
	glVertex2f(1.12,3.64);//P
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


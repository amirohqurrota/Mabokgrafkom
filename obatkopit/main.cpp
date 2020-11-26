#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

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

	glutSwapBuffers();
}
int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(728,728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("obat kopit");
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 15, 0, 20);
	glutMainLoop();
	return 0;
}

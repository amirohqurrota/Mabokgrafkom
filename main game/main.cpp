#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int vertikal=0;
int colliderWindowRight=85;
int colliderWindowLeft=0;
int colliderWindowTop=45;
int colliderWIndowBottom=0;
int posisiX1=42;
int posisiX2=49;

void objekDokter(){
    glTranslated(vertikal,0,0);
    vertikal=0;
    glBegin(GL_POLYGON);
    glColor3b(250,100,0);
    glVertex2f(posisiX1, 0);
	glVertex2f(posisiX1, 10);
	glVertex2f(posisiX2, 10);
	glVertex2f(posisiX2, 0);
	glEnd();
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3b(100,0,0);
	glVertex2f(20,45);
	glVertex2f(25,45);
	glVertex2f(25,40);
	glVertex2f(20,40);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3b(0,0,100);
	glVertex2f(65,45);
	glVertex2f(70,45);
	glVertex2f(70,40);
	glVertex2f(65,40);
	glEnd();
    objekDokter();

    glFlush();
	glutSwapBuffers();
}

void gerakDokter(int key, int x, int y){
    if(GetAsyncKeyState(VK_RIGHT)){
        if (posisiX2<=colliderWindowRight){
            vertikal+=10;
            glutPostRedisplay();
        }
    }
    if (GetAsyncKeyState(VK_LEFT)){
        if (posisiX1>=colliderWindowLeft)
            vertikal-=10;
            glutPostRedisplay();
    }
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");
	glutSpecialFunc(gerakDokter);
	glutDisplayFunc(displayMe);
	gluOrtho2D(0, 85, 0, 45);
	glutMainLoop();
	return 0;
}

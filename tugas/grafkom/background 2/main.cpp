#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);

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

    glPushMatrix();
    glTranslated(15,50,0);
    glBegin(GL_POLYGON); //bulan
    glColor3f(0.702, 0.702, 0.702);
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
	gluOrtho2D(0, 100 ,0, 100);
	init();
	glutMainLoop();
	return 0;
}

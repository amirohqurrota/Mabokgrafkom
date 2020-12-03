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

int horizontal=0;
int vertikalObat=45;
float posisiObat[4]={20,25,40,47};
int colliderWindowRight=78;
int colliderWindowLeft=5;
int colliderWindowTop=45;
int colliderWindowBottom=0;
float posisiDokter[4]={0,8,0,7};
char MENU[1000];
void cek(){
    cout << "posisiKanan: " << posisiDokter[1] << "\n";
    cout << "WindowRight: " << colliderWindowRight<< "\n";
    cout << "posisiKiri: " << posisiDokter[0] << "\n";
    cout << "WindowLeft: " << colliderWindowLeft<< "\n";
    cout << "Translasi: " << horizontal<< "\n";


}
void drawText(int x, int y, const char *string) {
	glRasterPos2f(x, y);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
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
    drawText(42,33,"MENU :");

    glPopMatrix();
}
void gerakDokter(int key, int x, int y){
    cek();
    if(GetAsyncKeyState(VK_RIGHT)){
        if (posisiDokter[1]<=colliderWindowRight){
            horizontal+=10;
            posisiDokter[1]+=10;
            posisiDokter[0]+=10;
            glutPostRedisplay();
        }
    }
    if (GetAsyncKeyState(VK_LEFT)){
        if (posisiDokter[0]>=colliderWindowLeft){
            horizontal-=10;
            posisiDokter[1]-=10;
            posisiDokter[0]-=10;
            glutPostRedisplay();
        }
    }

}
void colliderDokter(){
    glBegin(GL_POLYGON);
    glVertex2f(posisiDokter[0],posisiDokter[3]);
    glVertex2f(posisiDokter[0],posisiDokter[4]);
    glVertex2f(posisiDokter[1],posisiDokter[4]);
    glVertex2f(posisiDokter[1],posisiDokter[3]);
    glEnd();
}
void dokterObject(){
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
    glTranslated(25,30,0);
    glTranslated(0,vertikalObat,0);
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


//void obatMove(){
    //glPushMatrix();
    //obatObject();
    //while (posisiObat[3]>=posisiDokter[2]){
        //cout << "CEK LOOPING  ";
        //obatObject();
        //posisiObat[2]-=5;
        //posisiObat[3]-=5;
        //vertikalObat-=5;
        //glTranslated(0,vertikalObat,0);
        //glutTimerFunc(1,gerakObat,0);
        //glutPostRedisplay();
    //}
    //glPopMatrix();}

void timerVirus(int){
    virusObject();
    glutPostRedisplay();
    glutTimerFunc(1000/30,timerVirus,0);
    if (posisiVirus[3]>=-0){
        posisiVirus[2]-=0.5;
        posisiVirus[3]-=0.5;
        vertikalVirus-=1;
    }
    else{
        posisiVirus[2]=40;
        posisiVirus[3]=47;
        vertikalVirus=45;
    }

}
void backgroundObject(){
    glPushMatrix();
    glScaled(0.57,0.43,0);
    glBegin(GL_POLYGON); //langit biru
	glColor3f(0.0f,0.5f,1.0f);
	glVertex2f(0, 36);
	glVertex2f(0, 107);
	glVertex2f(149, 107);
	glVertex2f(149, 36);
	glEnd();

	glBegin(GL_POLYGON); //rumput hijau
	glColor3f(0.0f,1.0f,0.0f);
	glVertex2f(0, 36);
	glVertex2f(0, 17);
	glVertex2f(149, 17);
	glVertex2f(149, 36);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat muda seharusnya
	glColor4f(1.0f,0.5f,0.0f,0.0f);
	glVertex2f(0, 18);
	glVertex2f(0, 8);
	glVertex2f(150, 8);
	glVertex2f(150, 18);
	glEnd();

	glBegin(GL_POLYGON); //tanah coklat tua seharusnya
	glColor3b(74,38,4);
	glVertex2f(0, 8);
	glVertex2f(0, 0);
	glVertex2f(150, 0);
	glVertex2f(150, 8);
	glEnd();

    glBegin(GL_POLYGON); //matahari
    glColor4f(1.0f,1.0f,0.0f,0.0f);
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
	glColor3f(0.1f,0.0f,0.0f);
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
	glColor3f(0.5f,1.0f,1.0f);
	glVertex2f(54, 57);
	glVertex2f(54, 51);
	glVertex2f(59, 51);
	glVertex2f(59, 57);
	glEnd();

	glBegin(GL_POLYGON); //kaca kiri bawah
	glColor3f(0.5f,1.0f,1.0f);
	glVertex2f(54, 47);
	glVertex2f(54, 41);
	glVertex2f(59, 41);
	glVertex2f(59, 47);
	glEnd();

	glBegin(GL_POLYGON); //atap tengah
	glColor3f(0.1f,0.0f,0.0f);
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
	glColor3f(0.5f,1.0f,1.0f);
	glVertex2f(68, 55);
	glVertex2f(73, 55);
	glVertex2f(73, 50);
	glVertex2f(68, 50);
	glEnd();

	glBegin(GL_POLYGON); //kaca tengah kanan
	glColor3f(0.5f,1.0f,1.0f);
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
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2f(70, 45);
	glVertex2f(82, 45);
	glVertex2f(82, 30);
	glVertex2f(70, 30);
	glEnd();

	glBegin(GL_POLYGON); //atap kanan
	glColor3f(0.1f,0.0f,0.0f);
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
	glColor3f(0.5f,1.0f,1.0f);
	glVertex2f(93, 57);
	glVertex2f(98, 57);
	glVertex2f(98, 51);
	glVertex2f(93, 51);
	glEnd();

	glBegin(GL_POLYGON); //kaca kanan bawah
	glColor3f(0.5f,1.0f,1.0f);
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
    //menu();

    glBegin(GL_POLYGON);
	glColor3b(0,0,100);
	glVertex2f(65,45);
	glVertex2f(70,45);
	glVertex2f(70,40);
	glVertex2f(65,40);
	glEnd();

    obatObject();
    dokterMove();

    glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1368, 728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Hello world!");
	glutSpecialFunc(gerakDokter);
	glutTimerFunc(0,timerObat,0);
	glutDisplayFunc(displayMe);

	gluOrtho2D(0, 85, 0, 45);
	glutMainLoop();
	return 0;
}

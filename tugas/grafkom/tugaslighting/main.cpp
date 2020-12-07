#include <windows.h>
#include <GL/glut.h>

/* Variable Global */
char title[] = "Miqdad 3D Shapes";

/* Inisialisai OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Mengatur warna latar menjadi hitam dan buram
   glClearDepth(1.0f);                   // Mengaur kedalaman latar belakang ke terjauh
   glEnable(GL_DEPTH_TEST);   // Mengaktifkan pengujian kedalaman untuk z-culling
   glDepthFunc(GL_LEQUAL);    // Setel jenis uji kedalaman
   glShadeModel(GL_SMOOTH);   // Mengaktifkan bayangan halus
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Koreksi perspektif yang bagus
}

/* Handler untuk acara window-repaint. Dipanggil kembali ketika jendela pertama kali muncul dan kapan saja jendela perlu dicat ulang.*/
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);     // Untuk beroperasi pada matriks model-view


   // Membuat piramida terdiri dari 4 segitiga
   glLoadIdentity();                  // Atur ulang matriks model-view
   glTranslatef(-1.5f, 0.0f, -6.0f);  // Pindah ke kiri dan ke layar

   glBegin(GL_TRIANGLES);           // Mulai gambar piramid dengan 4 segitiga
      // Depan
      glColor3f(1.0f, 0.0f, 0.0f);     // Merah
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Hijau
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Biru
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Kanan
      glColor3f(1.0f, 0.0f, 0.0f);     // Merah
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Biru
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Hijau
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Belakang
      glColor3f(1.0f, 0.0f, 0.0f);     // Merah
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Hijau
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Biru
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Kiri
      glColor3f(1.0f,0.0f,0.0f);       // Merah
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Biru
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Hijau
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Selesai menggambar piramid

   glutSwapBuffers();  // Tukar frame depan dan belakang buffer (buffering ganda)
}

/* Handler untuk acara ukuran ulang jendela. Dipanggil kembali ketika jendela pertama kali muncul dan setiap kali jendela diukur ulang dengan lebar dan tinggi baru */
void reshape(GLsizei width, GLsizei height) {  // GLsizei untuk bilangan bulat non-negatif
   // Hitung rasio aspek dari jendela baru
   if (height == 0) height = 1;                // Mencegah pembagian dengan 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   //Menyetel viewport untuk menutupi jendela baru
   glViewport(0, 0, width, height);

   // Menyetel rasio aspek
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();             // Reset

   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Menghidupkan mode dobel
   glutInitWindowSize(640, 480);   // Ukuran tampilan jendela
   glutInitWindowPosition(50, 50); // Posisi jendela tampilan
   glutCreateWindow(title);          // Membuat jendela dengan judul title
   glutDisplayFunc(display);       // Memanggil function display
   glutReshapeFunc(reshape);       // Memanggil handler untuk merubah ukuran jendela
   initGL();                       // Inisialisasi OpenGL
   glutMainLoop();#include <GL/glut.h>
#include<math.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble size=1.0;
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display(void);
void idle(void)
{
    display();
}
void myinit()
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}
void display(void)
{
     glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-5.0);
    // Red color used to draw.
    glColor3f(0.9, 0.3, 0.2);
    // changing in transformation matrix.
    // rotation about X axis
    glRotatef(xRotated,1.0,0.0,0.0);
    // rotation about Y axis
    glRotatef(yRotated,0.0,1.0,0.0);
    // rotation about Z axis
    glRotatef(zRotated,0.0,0.0,1.0);
    // scaling transfomation
    glScalef(1.0,1.0,1.0);
    // built-in (glut library) function , draw you a sphere.
    glutSolidCube(size);
    // Flush buffers to screen

    glFlush();
    // sawp buffers called because we are using double buffering
   // glutSwapBuffers();
}

void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640,
            1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    //glViewport(0,0,w,h);  //Use the whole window for rendering
    glLoadIdentity();
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    xRotated = yRotated = zRotated = 30.0;
    xRotated=43;
    yRotated=50;
	glutCreateWindow("CUBE_LIGHT");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    myinit();
	glutIdleFunc(idle);
    glutMainLoop();
}
   return 0;
}

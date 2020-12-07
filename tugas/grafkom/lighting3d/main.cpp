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
   glutMainLoop();
   return 0;
}

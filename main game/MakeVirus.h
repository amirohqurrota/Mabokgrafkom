
class MakeVirus{
    public:
    int gerakVirus[2];
    float colliderVirus[4];
    int x2;
    int y1;
    int y2;

    void garisLuar(){
    glPushMatrix();
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(2.5, 4.8);
	glVertex2f(2.8, 4.8);
	glVertex2f(2.8, 4.45);
	glVertex2f(2.6, 4.45); //H
	glVertex2f(2.6, 3.9);  //
	glVertex2f(2.9, 3.9); // R
	glVertex2f(2.9,  3.7); //S
	glVertex2f(3.3, 3.7); // T
	glVertex2f(3.3, 3.9);
	glVertex2f(3.5, 3.9); //V
	glVertex2f(3.5, 4.5);
	glVertex2f(4.1, 4.5);
	glVertex2f(4.1, 4.3); //A-1
	glVertex2f(4.26, 4.3); //
	glVertex2f(4.26, 3.9); //
	glVertex2f(3.9, 3.9); //D-1
	glVertex2f(3.9, 4.1); //
	glVertex2f(3.7, 4.1); //
	glVertex2f(3.7, 3.7); //
	glVertex2f(3.54, 3.7); //
	glVertex2f(3.54, 3.34); //M-1
	glVertex2f(3.72, 3.34); //
	glVertex2f(3.72, 2.97); //
	glVertex2f(3.9, 2.97); // V-1
	glVertex2f(3.9, 2.56); // w-1
	glVertex2f(4.07, 2.56); // z-1
	glVertex2f(4.07, 2.4); // a-2
	glVertex2f(4.28, 2.4); // b-2
	glVertex2f(4.28, 2.20); //c-2
	glVertex2f(4.66, 2.20); //d-2
	glVertex2f(4.66, 1.81); //e-2
	glVertex2f(4.28, 1.81); //
	glVertex2f(4.28, 2.01); // g-2
	glVertex2f(4.09, 2.01); // h-2
	glVertex2f(4.09, 2.20); //i-2
	glVertex2f(3.90, 2.20); //
	glVertex2f(3.90, 2.00); // k-2
	glVertex2f(3.72, 2); // l-2
	glVertex2f(3.72, 1.61); //
	glVertex2f(3.53, 1.61); // n-2
	glVertex2f(3.53, 1.42); // o-2
	glVertex2f(3.16, 1.42); //
	glVertex2f(3.16, 1.26); //
	glVertex2f(2.97, 1.26); // r-2
	glVertex2f(2.97, 1.04); //
	glVertex2f(2.60, 1.04); // t-2
	glVertex2f(2.60, 0.68); // u-2
	glVertex2f(2.58, 0.68); // u-2
	glVertex2f(2.74, 0.68); // -2
	glVertex2f(2.74, 0.28); // w-2
	glVertex2f(2.49, 0.28); //
	glEnd();

	glScaled(-1,1,0);
    glTranslated(-5,0,0);
    glLineWidth(5);
    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex2f(2.5, 4.8);
	glVertex2f(2.8, 4.8);
	glVertex2f(2.8, 4.45);
	glVertex2f(2.6, 4.45); //H
	glVertex2f(2.6, 3.9);  //
	glVertex2f(2.9, 3.9); // R
	glVertex2f(2.9,  3.7); //S
	glVertex2f(3.3, 3.7); // T
	glVertex2f(3.3, 3.9);
	glVertex2f(3.5, 3.9); //V
	glVertex2f(3.5, 4.5);
	glVertex2f(4.1, 4.5);
	glVertex2f(4.1, 4.3); //A-1
	glVertex2f(4.26, 4.3); //
	glVertex2f(4.26, 3.9); //
	glVertex2f(3.9, 3.9); //D-1
	glVertex2f(3.9, 4.1); //
	glVertex2f(3.7, 4.1); //
	glVertex2f(3.7, 3.7); //
	glVertex2f(3.54, 3.7); //
	glVertex2f(3.54, 3.34); //M-1
	glVertex2f(3.72, 3.34); //
	glVertex2f(3.72, 2.97); //
	glVertex2f(3.9, 2.97); // V-1
	glVertex2f(3.9, 2.56); // w-1
	glVertex2f(4.07, 2.56); // z-1
	glVertex2f(4.07, 2.4); // a-2
	glVertex2f(4.28, 2.4); // b-2
	glVertex2f(4.28, 2.20); //c-2
	glVertex2f(4.66, 2.20); //d-2
	glVertex2f(4.66, 1.81); //e-2
	glVertex2f(4.28, 1.81); //
	glVertex2f(4.28, 2.01); // g-2
	glVertex2f(4.09, 2.01); // h-2
	glVertex2f(4.09, 2.20); //i-2
	glVertex2f(3.90, 2.20); //
	glVertex2f(3.90, 2.00); // k-2
	glVertex2f(3.72, 2); // l-2
	glVertex2f(3.72, 1.61); //
	glVertex2f(3.53, 1.61); // n-2
	glVertex2f(3.53, 1.42); // o-2
	glVertex2f(3.16, 1.42); //
	glVertex2f(3.16, 1.26); //
	glVertex2f(2.97, 1.26); // r-2
	glVertex2f(2.97, 1.04); //
	glVertex2f(2.60, 1.04); // t-2
	glVertex2f(2.60, 0.68); // u-2
	glVertex2f(2.58, 0.68); // u-2
	glVertex2f(2.74, 0.68); // -2
	glVertex2f(2.74, 0.28); // w-2
	glVertex2f(2.49, 0.28); //
	glEnd();
	glPopMatrix();
}

    void warnaVirus(){
        glPushMatrix();
        glBegin(GL_QUADS);
        glColor3f(0.718, 0.11, 0.11);
        glVertex2f(2.49, 4.84);
        glVertex2f(2.75, 4.84);
        glVertex2f(2.75, 4.45);
        glVertex2f(2.49, 4.45); //H

        glVertex2f(2.5, 3.9);  // i
        glVertex2f(2.9, 3.9); // R
        glVertex2f(3, 1.0); // R
        glVertex2f(2.5, 1.0);  // i
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(2.8, 3.7);  // i
        glVertex2f(3.54, 3.7); // R
        //glVertex2f(3.3, 3.7); // V
        glVertex2f(3.54, 1.43); // R
        glVertex2f(3.1, 1.31);
        glVertex2f(2.9, 1.23);  // i
        //glVertex2f(2.6, 1.2);  // i
        glEnd();


        glBegin(GL_POLYGON);
        glVertex2f(3.54, 3.35); //  M
        glVertex2f(3.72, 3.35); // B3
        glVertex2f(3.72, 2.97); // U1
        glVertex2f(3.850, 2.97); //V1
        glVertex2f(3.9, 2.56);  // W1
        glVertex2f(3.54, 2.56);  // D3
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(3.54, 2.56);  // D3
        glVertex2f(4.07,2.57);  // F3-1
        glVertex2f(4.12,2.38);  // F3
        glVertex2f(4.27,2.36);  // B2
        glVertex2f(4.27,2.01);  // G2
        glVertex2f(4.21,2.01);  // G2-2
        glVertex2f(3.99,2.2);  //
        glVertex2f(3.9,2.01);  // G2-2
        glVertex2f(3.7,2.01);  //
        glVertex2f(3.7,1.55);  // G3
        glVertex2f(3.54,1.55);  //
        glEnd();

        //TANGAN IRUS BAWAH
        glBegin(GL_POLYGON);
        glVertex2f(4.27, 2.2);  // B2
        glVertex2f(4.66, 2.2);  // D2
        glVertex2f(4.66, 1.82);  // E-2
        glVertex2f(4.27, 1.82);  //
        glEnd();

        //TANGAN IRUS atas
        glBegin(GL_QUADS);
        glVertex2f(3.20, 3.68);  //t
        glVertex2f(3.30, 3.9);  //
        glVertex2f(3.7, 3.9);  // j1
        glVertex2f(3.7, 3.68);  //

        glVertex2f(3.7, 3.9);  // j1
        glVertex2f(3.54, 3.9);  //
        glVertex2f(3.54, 4.46);  //
        glVertex2f(3.7, 4.46);  //

        glVertex2f(3.7, 4.1);  // j1
        glVertex2f(3.7, 4.46);  //
        glVertex2f(4.07, 4.46);  //
        glVertex2f(4.07, 4.1);  //

        glVertex2f(3.91, 3.94);  // d1
        glVertex2f(4.28, 3.94);  // c1
        glVertex2f(4.28, 4.3);  //
        glVertex2f(3.91, 4.3);  //b1
        glEnd();


        glBegin(GL_POLYGON);
        glVertex2f(2.58, 0.68); // u-2
        glVertex2f(2.74, 0.68); // -2
        glVertex2f(2.74, 0.28); // w-2
        glVertex2f(2.49, 0.28); //
        glEnd();

        glScaled(-1,1,0);
        glTranslated(-5,0,0);
        glBegin(GL_QUADS);
        glColor3f(0.718, 0.11, 0.11);
        glVertex2f(2.49, 4.84);
        glVertex2f(2.75, 4.84);
        glVertex2f(2.75, 4.45);
        glVertex2f(2.49, 4.45); //H

        glVertex2f(2.5, 3.9);  // i
        glVertex2f(2.9, 3.9); // R
        glVertex2f(3, 1.0); // R
        glVertex2f(2.5, 1.0);  // i
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(2.8, 3.7);  // i
        glVertex2f(3.54, 3.7); // R
        //glVertex2f(3.3, 3.7); // V
        glVertex2f(3.54, 1.43); // R
        glVertex2f(3.1, 1.31);
        glVertex2f(2.9, 1.23);  // i
        //glVertex2f(2.6, 1.2);  // i
        glEnd();


        glBegin(GL_POLYGON);
        glVertex2f(3.54, 3.35); //  M
        glVertex2f(3.72, 3.35); // B3
        glVertex2f(3.72, 2.97); // U1
        glVertex2f(3.850, 2.97); //V1
        glVertex2f(3.9, 2.56);  // W1
        glVertex2f(3.54, 2.56);  // D3
        glEnd();

        glBegin(GL_POLYGON);
        glVertex2f(3.54, 2.56);  // D3
        glVertex2f(4.07,2.57);  // F3-1
        glVertex2f(4.12,2.38);  // F3
        glVertex2f(4.27,2.36);  // B2
        glVertex2f(4.27,2.01);  // G2
        glVertex2f(4.21,2.01);  // G2-2
        glVertex2f(3.99,2.2);  //
        glVertex2f(3.9,2.01);  // G2-2
        glVertex2f(3.7,2.01);  //
        glVertex2f(3.7,1.55);  // G3
        glVertex2f(3.54,1.55);  //
        glEnd();

        //TANGAN IRUS BAWAH
        glBegin(GL_POLYGON);
        glVertex2f(4.27, 2.2);  // B2
        glVertex2f(4.66, 2.2);  // D2
        glVertex2f(4.66, 1.82);  // E-2
        glVertex2f(4.27, 1.82);  //
        glEnd();

        //TANGAN IRUS atas
        glBegin(GL_QUADS);
        glVertex2f(3.20, 3.68);  //t
        glVertex2f(3.30, 3.9);  //
        glVertex2f(3.7, 3.9);  // j1
        glVertex2f(3.7, 3.68);  //

        glVertex2f(3.7, 3.9);  // j1
        glVertex2f(3.54, 3.9);  //
        glVertex2f(3.54, 4.46);  //
        glVertex2f(3.7, 4.46);  //

        glVertex2f(3.7, 4.1);  // j1
        glVertex2f(3.7, 4.46);  //
        glVertex2f(4.07, 4.46);  //
        glVertex2f(4.07, 4.1);  //

        glVertex2f(3.91, 3.94);  // d1
        glVertex2f(4.28, 3.94);  // c1
        glVertex2f(4.28, 4.3);  //
        glVertex2f(3.91, 4.3);  //b1
        glEnd();


        glBegin(GL_POLYGON);
        glVertex2f(2.58, 0.68); // u-2
        glVertex2f(2.74, 0.68); // -2
        glVertex2f(2.74, 0.28); // w-2
        glVertex2f(2.49, 0.28); //
        glEnd();
        glPopMatrix();
    }

    void virusObject(awalX,awalY){
    glPushMatrix();

    glTranslated(awalX,awalY,0); //translated menurut posisi
    warnaVirus();
    garisLuar();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3f(0.718, 0.11, 0.11);
    glVertex2f(2.51, 4.75);
    glVertex2f(2.5, 0.32); //
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(2.5, 3.5);
    glVertex2f(2.5, 2.2); //

    glVertex2f(2.5, 1.9);
    glVertex2f(2.5, 1.6);
    glEnd();

    glLineWidth(8);
    glBegin(GL_LINES);
    glColor3f(0.827, 0.184, 0.184);
    glVertex2f(3.07,3.47);
    glVertex2f(3.07,3);

    glVertex2f(3.34,3.11);
    glVertex2f(3.34,2.0);

    glVertex2f(3.58,2.71);
    glVertex2f(3.58,2.39);
    glEnd();

    glPopMatrix();
}

    void MakeVirus(int posisiX,int posisiY){
        //}
        gerakVirus[0]=posisiX;
        gerakVirus[1]=posisiY;
        colliderVirus[0]=posisiX;
        colliderVirus[1]=posisiX+5;
        colliderVirus[2]=posisiY;
        colliderVirus[3]=posisiY+5;

        awalX=posisiX;
        awalY=posisiY;
        //int x2=x1+5;
        //int y1=inputany1;
        //int y2=y1+5;
        virusObject(awalX,awalY);

    }

    void virusMovement(){
        glPushMatrix();
        glTranslated(gerakVirus[0],gerakVirus[1],0););
        virusObject();
        glPopMatrix();
    }
};

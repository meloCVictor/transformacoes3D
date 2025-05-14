#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 10, 0, 0, 0, 0, 1, 0);

    // Cubo original no centro
    glColor3f(1, 1, 1);
    glutWireCube(1.0);

    // Cubo transladado
    glPushMatrix();
    glTranslatef(2.0, 0.0, 0.0); // move à direita
    glColor3f(1, 0, 0);
    glutWireCube(1.0);
    glPopMatrix();

    // Cubo rotacionado
    glPushMatrix();
    glRotatef(45, 0.0, 1.0, 0.0); // gira no eixo Y
    glTranslatef(-2.0, 0.0, 0.0); // move à esquerda após girar
    glColor3f(0, 1, 0);
    glutWireCube(1.0);
    glPopMatrix();

    // Cubo escalado
    glPushMatrix();
    glTranslatef(0.0, 2.0, 0.0); // sobe
    glScalef(1.0, 2.0, 1.0);     // escala no eixo Y
    glColor3f(0, 0, 1);
    glutWireCube(1.0);
    glPopMatrix();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Transformações");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

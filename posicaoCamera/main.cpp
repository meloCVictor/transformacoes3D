#include <GL/glut.h>

float camX = 2.0, camZ = 5.0; // posi��o da c�mera

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Proje��o perspectiva padr�o
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);

    // C�mera com coordenadas ajust�veis
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, 2.0, camZ,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glutWireCube(1.0);
    glFlush();
}

// Movimenta a c�mera no plano XZ com as setas
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) camX -= 0.2;
    if (key == GLUT_KEY_RIGHT) camX += 0.2;
    if (key == GLUT_KEY_UP) camZ -= 0.2;
    if (key == GLUT_KEY_DOWN) camZ += 0.2;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mover C�mera");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}

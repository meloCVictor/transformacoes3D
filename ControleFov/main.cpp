#include <GL/glut.h>
#include <iostream>

float fov = 60.0; // Campo de visão

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Define a projeção perspectiva com FOV ajustável
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, 1.0, 1.0, 100.0);

    // Configura a câmera (posição, ponto de foco, vetor "up")
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    // Desenha cubo no centro
    glutWireCube(1.0);
    glFlush();
}

// Controla o FOV com + e -
void keyboard(unsigned char key, int x, int y) {
    if (key == '+') {
        fov -= 5.0;
        if (fov < 10) fov = 10;
    } else if (key == '-') {
        fov += 5.0;
        if (fov > 170) fov = 170;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Controle do FOV");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

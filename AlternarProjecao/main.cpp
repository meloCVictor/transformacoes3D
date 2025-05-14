#include <GL/glut.h>

bool perspectiva = true; // Alternador de modo de projeção

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Alterna entre glOrtho e gluPerspective
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspectiva)
        gluPerspective(60.0, 1.0, 1.0, 100.0);
    else
        glOrtho(-2, 2, -2, 2, 1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);

    glutWireCube(1.0);
    glFlush();
}

// Alterna o tipo de projeção
void keyboard(unsigned char key, int x, int y) {
    if (key == 'p' || key == 'P') {
        perspectiva = !perspectiva;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ortográfica vs Perspectiva");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

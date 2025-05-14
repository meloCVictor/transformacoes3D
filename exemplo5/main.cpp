#include <GL/glut.h>

bool perspectiva = true;     // alternar entre ortho e perspectiva
float angle = 0;             // rotação animada
float camZ = 8.0;            // distância da câmera

void desenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspectiva)
        gluPerspective(60.0, 1.0, 1.0, 50.0);
    else
        glOrtho(-10, 10, -10, 10, -10, 50);

    // Câmera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 5, camZ, 0, 0, 0, 0, 1, 0);

    // Base/Chão
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10);
    glVertex3f(10, 0, -10);
    glVertex3f(10, 0, 10);
    glVertex3f(-10, 0, 10);
    glEnd();

    // Objeto 1: Teapot
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(-4, 1, 0);
    glRotatef(angle, 0, 1, 0);  // rotação contínua
    glutWireTeapot(1);
    glPopMatrix();

    // Objeto 2: Cube
    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(0, 1, 0);
    glScalef(1, 1.5, 1);  // estica em Y
    glutWireCube(2);
    glPopMatrix();

    // Objeto 3: Sphere
    glPushMatrix();
    glColor3f(0, 0, 1);
    glTranslatef(4, 1, 0);
    glutWireSphere(1, 16, 16);
    glPopMatrix();

    // Objeto 4: Cone
    glPushMatrix();
    glColor3f(1, 1, 0);
    glTranslatef(-2, 1, -4);
    glRotatef(-90, 1, 0, 0);  // alinhar cone na vertical
    glutWireCone(1, 2, 16, 16);
    glPopMatrix();

    // Objeto 5: Torus
    glPushMatrix();
    glColor3f(1, 0, 1);
    glTranslatef(2, 1, -4);
    glRotatef(angle, 1, 1, 0);  // rotação 3D
    glutWireTorus(0.3, 0.7, 16, 16);
    glPopMatrix();

    glFlush();
}

void teclado(unsigned char key, int x, int y) {
    if (key == 'p' || key == 'P') {
        perspectiva = !perspectiva;
        glutPostRedisplay();
    }
}

void especiais(int key, int x, int y) {
    if (key == GLUT_KEY_UP) camZ -= 0.5;
    if (key == GLUT_KEY_DOWN) camZ += 0.5;
    glutPostRedisplay();
}

void idle() {
    angle += 0.5;
    if (angle > 360) angle -= 360;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Galeria de Formas 3D - Wireframe");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(desenhaCena);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(especiais);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

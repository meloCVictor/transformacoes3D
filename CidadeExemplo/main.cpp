#include <GL/glut.h>
#include <cmath>

// Estado da projeção
bool perspectiva = true;

// Câmera
float camX = 6.0, camZ = 10.0;

// Desenha um prédio simples
void drawBuilding(float x, float y, float z, float h, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y + h / 2.0, z);  // Move o cubo para cima
    glScalef(1.0, h, 1.0);           // Escala em Y
    glColor3f(r, g, b);
    glutSolidCube(1.0);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Projeção
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (perspectiva)
        gluPerspective(60.0, 1.0, 1.0, 100.0);
    else
        glOrtho(-10, 10, -10, 10, 1, 100);

    // Câmera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camX, 5.0, camZ, 0, 0, 0, 0, 1, 0);

    // Chão
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(-10, 0, -10);
    glVertex3f(10, 0, -10);
    glVertex3f(10, 0, 10);
    glVertex3f(-10, 0, 10);
    glEnd();

    // Prédios com transformações
    drawBuilding(-4, 0, 0, 3, 1, 0, 0); // Vermelho
    drawBuilding(0, 0, 0, 5, 0, 1, 0);  // Verde
    drawBuilding(4, 0, 0, 2, 0, 0, 1);  // Azul

    // Torre com rotação
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glRotatef(45, 0, 1, 0); // Rotação no eixo Y
    glScalef(0.5, 6.0, 0.5);
    glColor3f(1, 1, 0);
    glutSolidCube(1.0);
    glPopMatrix();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 'p' || key == 'P') {
        perspectiva = !perspectiva;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) camX -= 0.5;
    if (key == GLUT_KEY_RIGHT) camX += 0.5;
    if (key == GLUT_KEY_UP) camZ -= 0.5;
    if (key == GLUT_KEY_DOWN) camZ += 0.5;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Cena 3D com Transformações");

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();
    return 0;
}

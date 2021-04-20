#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265358979323846

GLfloat position_a = 0.0f;
GLfloat speed_a = 0.0f;

GLfloat position_b = 0.0f;
GLfloat speed_b = 0.0f;

GLfloat position_c = 0.0f;
GLfloat speed_c = 0.0f;

GLfloat position_d = 0.0f;
GLfloat speed_d = 0.0f;

void Idle()
{
    glutPostRedisplay();
}

void update_a(int value)
{

    if(position_a <-3.0)
    {
        position_a = 1.0f;
    }
    position_a -= speed_a;

	glutTimerFunc(100, update_a, 0);
}

void update_b(int value)
{

    if(position_b <-3.0)
    {
        position_b = 1.0f;
    }
    position_b -= speed_b;

	glutTimerFunc(100, update_b, 0);
}

void update_c(int value)
{

    if(position_c <-3.0)
    {
        position_c = 1.0f;
    }
    position_c -= speed_c;

	glutTimerFunc(100, update_c, 0);
}

void update_d(int value)
{

    if(position_d <-3.0)
    {
        position_d = 1.0f;
    }
    position_d -= speed_d;

	glutTimerFunc(100, update_d, 0);
}

void cube()
{
    glBegin(GL_QUADS);
    glColor3ub(51, 102, 153);
    glVertex2f(-0.5, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void triangle()
{
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);
    glVertex2f(0.0, 0.5f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

void circle()
{
    int is;
    GLfloat xs=0.0f;
    GLfloat ys=0.0f;
    GLfloat radiuss =.5f;
    int triangleAmounts = 100;
    GLfloat twicePis = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 0, 255);
    glVertex2f(xs, ys);
    for(is = 0; is <= triangleAmounts; is++)
    {
        glVertex2f(xs+(radiuss*cos(is*twicePis/triangleAmounts)), ys+(radiuss*sin(is*twicePis/triangleAmounts)));
    }
    glEnd();
}

void rectangle()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 153, 51);
    glVertex2f(-0.3, 0.5f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
    glEnd();
}

void refresh()
{
    position_a = 0.0f;
    speed_a = 0.0f;

    position_b = 0.0f;
    speed_b = 0.0f;

    position_c = 0.0f;
    speed_c = 0.0f;

    position_d = 0.0f;
    speed_d = 0.0f;
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'F':
            refresh();
        break;

        case 'f':
            refresh();
        break;
    }
}

void handleMousepress(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
    {
        speed_a = 0.09;
        speed_b = 0.09;
    }

    else if (button == GLUT_RIGHT_BUTTON)
    {
        speed_c = 0.09;
        speed_d = 0.09;
    }
}

void display()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(-0.5, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glPushMatrix();
    glTranslatef(-position_a,0.0, 0.0f);
        cube();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(-0.8, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glPushMatrix();
    glTranslatef(-position_b,0.0, 0.0f);
        triangle();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(0.5, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glPushMatrix();
    glTranslatef(position_c, 0.0, 0.0f);
        rectangle();
    glPopMatrix();
    glLoadIdentity();

    glTranslatef(0.8, 0.0, 0.0);
    glScalef(0.4, 0.4, 0.0);
    glPushMatrix();
    glTranslatef(position_d, 0.0, 0.0f);
        circle();
    glPopMatrix();
    glLoadIdentity();

	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Moving Objects");
	glutDisplayFunc(display);
	glutTimerFunc(100, update_a, 0);
	glutTimerFunc(100, update_b, 0);
	glutTimerFunc(100, update_c, 0);
	glutTimerFunc(100, update_d, 0);
	glutIdleFunc(Idle);
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(handleMousepress);
	glutMainLoop();
	return 0;
}


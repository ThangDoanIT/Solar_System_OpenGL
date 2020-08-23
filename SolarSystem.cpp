#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "Dependencies/freeglut/glut.h"
#include <math.h>
#include <sys/timeb.h>
#include <sys/utime.h>

#define  PI 3.141592655389
static int rotate = 1;
static GLfloat spin = 0.0;
static int der = 0;
static int d = 1;
static float earth = 360 / 365.2;
static float g_x = 0, g_y = 5, g_z = 20;
static int year = 0, day = 0, moon = 0,
mars = 0, jupiter = 0, saturn = 0, uranus = 0, neptune = 0 ;
int maxy = 1;

int getMilliCount() {
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

void sleep(int sleeptime)
{
	int count = 0;
	int beginsleep = getMilliCount();
	while (getMilliCount() - beginsleep < sleeptime)
	{
		count++;
	}
}

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_FLAT);
}

void draw()
{

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, -10.0, 0.0);
	glVertex3f(0.0, 10.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, -10.0);
	glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);

	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(cos(i) * 2, 0.0, sin(i) * 2);
	}

	glEnd();

	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(cos(i) * 4, 0.0, sin(i) * 4);
	}

	glEnd();

	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000)
	{
		glVertex3f(cos(i) * 3, 0.0, sin(i) * 3);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000)
	{
		glVertex3f(cos(i) * 5, 0.0, sin(i) * 5);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000)
	{
		glVertex3f(cos(i) * 6, 0.0, sin(i) * 6);
	}
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000)
	{
		glVertex3f(cos(i) * 7, 0.0, sin(i) * 7);
	}
	glEnd();
	glPopMatrix();

}

void display(void) {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(g_x, g_y, g_z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	glColor3f(247.0f/255.0f, 54.0f / 255.0f, 25.0f / 255.0f);
	glutSolidSphere(1.0, 100, 100);

	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	//earth
	glColor3f(73.0f / 255.0f, 105.0f / 255.0f, 235.0f / 255.0f);

	glutSolidSphere(0.25, 50, 100);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(cos(i) * 0.5, 0.0, sin(i) * 0.5);
	}
	glEnd();

	glRotatef((GLfloat)moon, 0.0, 12.0, 0.0);
	glTranslatef(0.5, 0.0, 0.0);
	//moon
	glColor3f(219.0f / 255.0f, 211.0f / 255.0f, 206.0f / 255.0f);

	glutSolidSphere(0.08, 10, 100);

	glPopMatrix();

	glPushMatrix();


	glRotatef((GLfloat)mars, 0.0, 1.0, 0.0);
	glTranslatef(3, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);


	//mars
	glColor3f(242.0f / 255.0f, 134.0f / 255.0f, 80.0f / 255.0f);

	glutSolidSphere(0.23, 100, 100);
	glPopMatrix();
	/////////////////
	glPushMatrix();
	//jupiter
	glRotatef((GLfloat)jupiter, 0.0, 1.0, 0.0);
	glTranslatef(4, 0.0, 0.0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glColor3f(227.0f / 255.0f, 97.0f / 255.0f, 16.0f / 255.0f);
	glutSolidSphere(0.5, 100, 100);

	glPopMatrix();
	/////////////////
	glPushMatrix();

	glRotatef((GLfloat)saturn, 0.0, 1.0, 0.0);
	glTranslated(5.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	//saturn
	glColor3f(242.0f / 255.0f, 210.0f / 255.0f, 65.0f / 255.0f);
	glutSolidSphere(0.6, 50, 100);
	//circle saturn
	glColor3f(240.0f / 255.0f, 223.0f / 255.0f, 146.0f / 255.0f);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(cos(i) * 0.6, sin(i) * 0.6, 0.0);
		glVertex3f(cos(i) * 0.62, sin(i) * 0.62, 0.0);
		glVertex3f(cos(i) * 0.64, sin(i) * 0.64, 0.0);
		glVertex3f(cos(i) * 0.66, sin(i) * 0.66, 0.0);
		glVertex3f(cos(i) * 0.68, sin(i) * 0.68, 0.0);
		glVertex3f(cos(i) * 0.7, sin(i) * 0.7, 0.0);
		glVertex3f(cos(i) * 0.72, sin(i) * 0.72, 0.0);
		glVertex3f(cos(i) * 0.74, sin(i) * 0.74, 0.0);
		glVertex3f(cos(i) * 0.76, sin(i) * 0.76, 0.0);
		glVertex3f(cos(i) * 0.78, sin(i) * 0.78, 0.0);
		glVertex3f(cos(i) * 0.8, sin(i) * 0.8, 0.0);
		glVertex3f(cos(i) * 0.82, sin(i) * 0.82, 0.0);
		glVertex3f(cos(i) * 0.84, sin(i) * 0.84, 0.0);
		glVertex3f(cos(i) * 0.86, sin(i) * 0.86, 0.0);
		glVertex3f(cos(i) * 0.88, sin(i) * 0.88, 0.0);
		glVertex3f(cos(i) * 0.9, sin(i) * 0.9, 0.0);
		glVertex3f(cos(i) * 0.92, sin(i) * 0.92, 0.0);
		glVertex3f(cos(i) * 0.94, sin(i) * 0.94, 0.0);
		glVertex3f(cos(i) * 0.96, sin(i) * 0.96, 0.0);
		glVertex3f(cos(i) * 0.98, sin(i) * 0.98, 0.0);
	}

	glEnd();

	glPopMatrix();

	/// //////////////////////////////

	glPushMatrix();
	glRotatef((GLfloat)uranus, 0.0, 1.0, 0.0);

	glTranslated(6.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	//uranus
	glColor3f(103.0f / 255.0f, 192.0f / 255.0f, 240.0f / 255.0f);
	glutSolidSphere(0.4, 50, 100);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
	for (double i = 0; i < 2 * PI; i += PI / 1000) {

		glVertex3f(0.0,cos(i) * 0.6, sin(i) * 0.6);
	}

	glEnd();

	glPopMatrix();

	/// /////////////////

	glPushMatrix();
	glRotatef((GLfloat)neptune, 0.0, 1.0, 0.0);

	glTranslated(7.0, 0, 0);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	//neptune
	glColor3f(26.0f / 255.0f, 114.0f / 255.0f, 237.0f / 255.0f);
	glutSolidSphere(0.3, 50, 100);
	glPopMatrix();

	draw();

	glutSwapBuffers();

}

void calSC(double dec)
{
	g_x = 5 * sin(dec);
	g_z = 5 * cos(dec);
	g_y = g_y + 0.1 * maxy;
	if (g_y > 22 || g_y < -22)
	{
		maxy *= -1;
	}
}

void spinDisplay(void)
{
	der += 10;
	calSC((double)der / 360);
	year = (year - rotate * d) % 360;

	day = (day - rotate * d) % 360;
	/*saturn = (saturn - rotate * 1) % 360;*/
	moon = (moon - rotate * d * 12) % 360;
	mars = (mars - rotate * d * 4) % 360;
	jupiter = (jupiter - rotate * d * 12) % 360;
	saturn = (saturn - rotate * d * 6) % 360;
	uranus = (uranus - rotate * d * 10) % 360;
	neptune = (neptune - rotate * d * 3) % 360;

	int beginFrame = getMilliCount();

	glutPostRedisplay(); /* thông báo cho chương trình rằng: cần phải thực
						 hiện việc vẽ lại */
	int timeDiff = getMilliCount() - beginFrame;
	if (timeDiff < 40) // 25FPS
	{
		sleep(40 - timeDiff);
	}
}

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// gluLookAt(2.0, 5.0, 5.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '1':
		rotate = 1;
		spin = spin + 0.5;
		d = d + 0.2;
		glutIdleFunc(spinDisplay);
		break;
	case '2':
		rotate = -1;
		spin = spin + 0.5;
		d = d + 0.2;
		glutIdleFunc(spinDisplay);
		break;
	default:          
		break;
	}
}

void keyStartEnd(unsigned char key, int x, int y)
{
	switch (key)
	{

	default:
		break;
	}
};

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 600);

	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

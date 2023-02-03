#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
//int moon data
int moon = 35;
//daystate
int daystate=1;
//titanic data init
int movetitanic=0;
int movetitanicspd=1;
//boat data init;
int moveboat=0;
int moveboat1=0;
int speedboat=0;
int speedboat1=0;
//extras
int pause=0;
float point;
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	//you can have upto 8 lighting
	//glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1 //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}
void circle(int x, int y, int r, GLfloat color[]){
    //CREATING CIRCLE USING line loop mehod explicit curve
	//x+=12;y+=30;
    if(r==0)return;
	int circle_points = 100;
	GLfloat toPi = 2 * 3.1416,cp_x,cp_y;

	glBegin(GL_TRIANGLE_FAN);
		glColor3f(color[0],color[1],color[2]);
		for(int i = 0; i <= circle_points;i++){
			cp_x = x + (r * cos(i *  toPi / circle_points));
			cp_y = y + (r * sin(i * toPi / circle_points));
			glVertex2f(cp_x,cp_y);
		}
	glEnd();
}
void rotateAroundPt(int px,int py,int r,float point){
	int circle_points = 100;
	GLfloat toPi = 2 * 3.1416;
	int x =px + (r * cos(point *  toPi / circle_points));
	int y =py + (r * sin(point * toPi / circle_points));
	glVertex2i(x,y);
}
//custom library files
#include "library_objects.h"
//

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
			break;
        case 'i':
            movetitanicspd++;
            break;
        case 'l':
            movetitanic-=6;
            pause=1;
            break;
        case 'r':
            movetitanic+=6;
            pause=0;
            break;


	}
}

void mainScene(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat ambientColor[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.2, 0.2, 0.2) and intensity //can be greater than 1 so not like color
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	GLfloat lightColor0[] = {0.35f, 0.35f, 0.35f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {800.0f, 300.0f, 100.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	smallboats(-50+moveboat1,215);
	smallboats(130+moveboat,250);

	hills();
	windmill(0);
	windmill(250);
	windmill(500);
	GLfloat Circlec[]= {1.0f, 1.0f, 1.0f};
	circle(1200,561,moon,Circlec);
	nightsky(daystate);
	boathide();
	TheTitanic(movetitanic,movetitanic);
	sea();

    glFlush();
	glutSwapBuffers();
}

void update(int value) {
	//add the code here
	moon = 35;
	daystate=1;
	if(movetitanic>=880){
        moveboat+=2;
        moveboat1+=4;
        daystate=0;
        point+=2;
        moon=0;
	}else if (pause==0){
	    movetitanic+=movetitanicspd+6;
	}
	moveboat+=4;
    moveboat1+=6;
	if(moveboat>=220 && moveboat1>=440){
        moveboat=-1100;
        moveboat1=-1000;
	}
	point+=0.05;
    //add the code here

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
    //glutReshapeWindow(1366,768);
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("The hidden titanic");
	//glutFullScreen();
	//glutInitWindowSize(1366,768);
    glutReshapeWindow(1366,768);
	glOrtho(0,1275,0,695,0,20);//for work in graph.
	initRendering();
	glutDisplayFunc(mainScene);
	glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}

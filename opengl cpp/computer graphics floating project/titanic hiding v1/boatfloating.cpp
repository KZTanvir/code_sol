#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include "library_objects.h"
//titanic data init
int movetitanic=0;
int hc=1;
int xdec=0;
//boat data init;
int moveboat=0;
int moveboat1=0;
int speedboat=0;
int speedboat1=0;
//extras
int keypress=0;
 int cpx=0,cpy=0;
 int cpx1=0,cpy1=0;
using namespace std;
float point;
void rotateAroundPt(int px,int py,int r,float point){
	int circle_points = 100;
	GLfloat toPi = 2 * 3.1416; 
	int x =px + (r * cos(point *  toPi / circle_points));
	int y =py + (r * sin(point * toPi / circle_points));
	glVertex2i(x,y);
}
int lol=0;
void windmill(int right){
	GLfloat Circlec[]= {0.120f, 0.065f, 0.065f};
	circle(105+right,561,11,Circlec);
	glBegin(GL_TRIANGLES);
		glColor3f(.225f, .225f, .225f);
		glVertex2i(105+right,560);
		rotateAroundPt(105+right,560,70,point);
		rotateAroundPt(105+right,560,50,point+4);

		glVertex2i(105+right,560);lol++;
		rotateAroundPt(105+right,560,70,point+33);
		rotateAroundPt(105+right,560,50,point+37);
		//glVertex2i( 38+right,580);
		//glVertex2i( 36+right,569);

		glVertex2i(105+right,560);
		rotateAroundPt(105+right,560,70,point+66);
		rotateAroundPt(105+right,560,50,point+70);
		glEnd();
	glBegin(GL_QUADS);
		glColor3f(.150f, .150f, .150f);
		glVertex2i(100+right,440);
		glVertex2i(110+right,440);
		glVertex2i(110+right,560);
		glVertex2i(100+right,560);
	glEnd();
}
void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
			break;
        case 'i':
            movetitanic++;
			moveboat++;
			moveboat1--;
			break;
		case 'j':
			movetitanic-=2;
			moveboat--;
			moveboat1++;
			break;
		case 'k':
			exit(0);

	}
}

void chimni(int x){
		glColor3f(0.0f, 0.0f, 0.0f);//rgba(128,73,64,255)
		glVertex2i(220+x,270);
		glVertex2i(280+x,270);
		glVertex2i(280+x,325);
		glVertex2i(220+x,325);
		glColor3f(0.128f, 0.073f, 0.064f);
		glVertex2i(220+x,325);
		glVertex2i(280+x,325);
		glVertex2i(280+x,335);
		glVertex2i(220+x,335);
}

void TheTitanic(int hidecor,int xinc,int xdec0){

	GLfloat Circlec[]= {1.0f, 1.0f, 1.0f};
	circle(160+xinc,100,28*hidecor,Circlec);
	circle(270+xinc,100,28*hidecor,Circlec);
	circle(400+xinc,100,28*hidecor,Circlec);
	circle(530+xinc,100,28*hidecor,Circlec);
	circle(670+xinc,100,28*hidecor,Circlec);

	circle(220+xinc,190,15*hidecor,Circlec);
	circle(340+xinc,190,15*hidecor,Circlec);
	circle(460+xinc,190,15*hidecor,Circlec);
	circle(600+xinc,190,15*hidecor,Circlec);

	circle(190+xinc,230,15*hidecor,Circlec);
	circle(245+xinc,230,15*hidecor,Circlec);
	circle(300+xinc,230,15*hidecor,Circlec);
	circle(355+xinc,230,15*hidecor,Circlec);
	circle(410+xinc,230,15*hidecor,Circlec);
	circle(465+xinc,230,15*hidecor,Circlec);
	circle(520+xinc,230,15*hidecor,Circlec);
	circle(575+xinc,230,15*hidecor,Circlec);

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(170+xinc,20);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(660+xdec0,20);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(680+xdec0,40);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(150+xinc,40);

		glColor3f(0.150f, 0.062f, 0.057f);
		glVertex2i(150+xinc,40);
		glColor3f(0.244f, 0.113f, 0.034f);
		glVertex2i(680+xdec0,40);
		glColor3f(0.244f, 0.113f, 0.034f);
		glVertex2i(810+xdec0,150);
		glColor3f(0.150f, 0.062f, 0.057f);
		glVertex2i(20+xinc,150);

		glColor3f(0.183f, 0.121f, 0.087f);//rgba(183,121,87,255)
		glVertex2i(20+xinc,150);
		glVertex2i(810+xdec0,150);
		glVertex2i(810+xdec0,170);
		glVertex2i(20+xinc,170);

		glColor3f(0.127f, 0.127f, 0.127f);//rgba(127,127,127,255)
		glVertex2i(80+xinc,170);
		glVertex2i(760+xdec0,170);
		glVertex2i(760+xdec0,210);
		glVertex2i(80+xinc,210);

		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(738+xdec0,220);
		glVertex2i(712+xdec0,240);
		glVertex2i(660+xinc,240);
		glVertex2i(660+xinc,220);

		glColor3f(0.220f, 0.220f, 0.220f);
		glVertex2i(110+xinc,210);
		glVertex2i(750+xdec0,210);
		glVertex2i(700+xdec0,250);
		glVertex2i(110+xinc,250);

		
		glColor3f(0.185f, 0.122f, 0.081f);//rgba(185,122,81,255)
		glVertex2i(110+xinc,250);
		glVertex2i(700+xdec0,250);
		glVertex2i(600+xdec0,270);
		glVertex2i(210+xinc,270);

		chimni(30+xinc);
		chimni(140+xinc);
		chimni(250+xinc);

	glEnd();
}
void smallboats(int x,int y){
	glBegin(GL_QUADS);
		glColor3f(0.002f, 0.131f, 0.013f);//rgba(2,131,13,255)
		glVertex2i(925+x,125+y);
		glVertex2i(990+x,125+y);//rgba(28,167,61,255)
		glColor3f(0.000f, 0.200f, 0.000f);
		glVertex2i(1030+x,170+y);
		glVertex2i(880+x,170+y);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3f(0.255f, 0.0f, 0.0f);
		glVertex2i(1010+x,175+y);
		glVertex2i(970+x,175+y);
		glVertex2i(970+x,290+y);

		glVertex2i(965+x,175+y);
		glVertex2i(965+x,230+y);
		glVertex2i(930+x,175+y);
	glEnd();
}
void boathide(){
	glBegin(GL_QUADS);
		glColor3f(0.051f, 0.153f, 0.255f);
		glVertex2i(900,20);
		glVertex2i(1400,20);
		glVertex2i(1400,335);
		glVertex2i(900,335);
	glEnd();
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
	circle(1200,561,35,Circlec);
	nightsky();
	boathide();



	TheTitanic(1,movetitanic,movetitanic);
	sea();
	
    glFlush();
	glutSwapBuffers();
}

void update(int value) {
	//add the code here

	moveboat+=4;
	moveboat1++;
	movetitanic++;
	if(moveboat>200){
		moveboat=-1400;
	}
	point++;

    //add the code here

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
    //glutReshapeWindow(1366,768);
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("The Moving Stickman");
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
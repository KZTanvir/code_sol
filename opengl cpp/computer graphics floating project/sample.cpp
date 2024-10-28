#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include <time.h>
using namespace std;

//left leg
int llx[3]={0,0,0};
int lly[3]={0,0,0};
//right leg
int rlx[3]={0,0,0};
int rly[3]={0,0,0};
//left arm
int lax[3]={0,0,0};
int lay[3]={0,0,0};
//right arm
int rax[3]={0,0,0};
int ray[3]={0,0,0};
//body
int bx[3]={0,0,0};
int by[3]={0,0,0};
//head
int hx=0;
int hy=0;
//hand gun
int hgx[4]={0,0,0,0};
int hgy[4]={0,0,0,0};
//flags
//
//movements
//
void head(int x1,int y1){
    //CREATING CIRCLE USING line loop mehod explicit curve
	int x =12 + x1;//x coordinate of center
	int y =30 + y1;//y coordinate of center
	int r =5;//radius of circle
	//
	int circle_points = (x+y)*r;
	GLfloat toPi = 2 * 3.1416,cp_x,cp_y;
	
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 1.0);
		for(int i = 0; i <= circle_points;i++){ 
			cp_x = x + (r * cos(i *  toPi / circle_points));
			cp_y = y + (r * sin(i * toPi / circle_points));
			glVertex2f(cp_x,cp_y);  
		}
	glEnd();
}

void body(int x1,int y1,int x2,int y2){
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
    	glVertex2i(12+x1,10+y1);
        glVertex2i(12+x2,25+y2);
    glEnd();
}

void leftArm(int x1,int y1,int x2,int y2,int x3,int y3){
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);

        glVertex2i(7+x1,10+y1);
        glVertex2i(8+x2,16+y2);
        
        glVertex2i(8+x2,16+y2);
    	glVertex2i(12+x3,23+y3);

        glEnd();
}

void rightArm(int x1,int y1,int x2,int y2,int x3,int y3){
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
    	glVertex2i(12+x1,23+y1);
        glVertex2i(18+x2,22+y2);
        glVertex2i(18+x2,22+y2);
        glVertex2i(26+x2,23+y2);

        glEnd();
}

void handGun(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
    glBegin(GL_QUADS);
		glColor3f(1.0, 1.0, 1.0);
		glVertex2i(26+x1,24+y1);
		glColor3f(0.0, 1.0, 1.0);
		glVertex2i(30+x2,24+y2);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(30+x3,22+y3);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2i(26+x4,22+y4);

	glEnd();
}

void leftLeg(int x1,int y1,int x2,int y2,int x3,int y3){
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
    	glVertex2i(6+x1,0+y1);
		glVertex2i(10+x2,5+y2);

        glVertex2i(10+x2,5+y2);
		glVertex2i(12+x3,10+y3);

        glEnd();
}

void rightLeg(int x1,int y1,int x2,int y2,int x3,int y3){
    glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
    	glVertex2i(12+x1,10+y1);
        glVertex2i(17+x2,5+y2);

        glVertex2i(17+x3,5+y3);
        glVertex2i(18+x1,0+y1);

        glEnd();
}

void stickman(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2i(0,200);
    glVertex2i(0,695);
    glVertex2i(1275,695);
    glVertex2i(1275,200);
    glEnd();
    glFlush();

    glFlush();
}

void update(int value) {
	//add the code here

    //add the code here

	glutPostRedisplay(); ////Tell GLUT that the scene has changed
	glutTimerFunc(40, update, 0);
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("The Moving Stickman");
	glutInitWindowSize(1275,695);
	//glutInitWindowPosition(100,100);
	glOrtho(-10,5000,-10,5000,-1,1);//for work in graph.

	glutDisplayFunc(stickman);
    glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}
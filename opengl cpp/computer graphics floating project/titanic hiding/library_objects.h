#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	//you can have upto 8 lighting
	glEnable(GL_LIGHT0); //Enable light #0
	//glEnable(GL_LIGHT1); //Enable light #1 //Automatically normalize normals
	//glShadeModel(GL_SMOOTH); //Enable smooth shading
}

void circle(int x, int y, int r, GLfloat color[]){
    //CREATING CIRCLE USING line loop mehod explicit curve
	//x+=12;y+=30;
    if(r==0)return;
	int circle_points = (x+y)*r;
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

void nightsky(){
	glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.200f);
		glVertex2i(0,695);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(0,440);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2i(1275,440);
		glColor3f(0.0f, 0.0f, 0.200f);
		glVertex2i(1275,695);
	glEnd();
}
void sea(){
	glBegin(GL_QUADS);
		glColor3f(0.051f, 0.153f, 0.255f);
		glVertex2i(0,440);
		glVertex2i(0,0);
		glVertex2i(1275,0);
		glVertex2i(1275,440);
	glEnd();
}
void hills(){
	glBegin(GL_TRIANGLES);
		glColor3f(0.100f, 0.050f, 0.0f);
		glVertex2i(170,440);
		glVertex2i(250,520);
		glVertex2i(370,440);

		glVertex2i(340,440);
		glVertex2i(470,480);
		glVertex2i(640,440);

		glColor3f(.255f, 0.153f, 0.051f);
		glVertex2i(80,440);
		glVertex2i(160,500);
		glVertex2i(240,440);

		glEnd();

}
void windmill(int right){
	GLfloat Circlec[]= {0.120f, 0.065f, 0.065f};
	circle(105+right,561,11,Circlec);
	glBegin(GL_QUADS);

		glColor3f(.225f, .225f, .225f);
		glVertex2i(110+right,560);
		glVertex2i(100+right,560);
		glVertex2i(118+right,498);
		glVertex2i(128+right,502);

		glVertex2i(100+right,558);
		glVertex2i(100+right,568);
		glVertex2i( 38+right,580);
		glVertex2i( 36+right,569);

		glVertex2i(110+right,560);
		glVertex2i(155+right,608);
		glVertex2i(146+right,615);
		glVertex2i(105+right,570);

		glColor3f(.150f, .150f, .150f);
		glVertex2i(100+right,440);
		glVertex2i(110+right,440);
		glVertex2i(110+right,560);
		glVertex2i(100+right,560);
		glEnd();
}
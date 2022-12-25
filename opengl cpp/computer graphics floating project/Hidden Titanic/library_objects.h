#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
#include<math.h>

void windmill(int right){
	GLfloat Circlec[]= {0.120f, 0.065f, 0.065f};
	circle(105+right,561,11,Circlec);
	glBegin(GL_TRIANGLES);
		glColor3f(.225f, .225f, .225f);
		glVertex2i(105+right,560);
		rotateAroundPt(105+right,560,70,point);
		rotateAroundPt(105+right,560,50,point+4);

		glVertex2i(105+right,560);
		rotateAroundPt(105+right,560,70,point+33);
		rotateAroundPt(105+right,560,50,point+37);

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
void nightsky(int night){
    GLfloat up[] = {0.152f,0.223f,0.212f};
    GLfloat dn[] = {0.0f,0.255f,0.255f};
    if(night==1){
        up[0]=0.0f;up[1]=0.0f;up[2]=0.200f;
        dn[0]=0.0f;dn[1]=0.0f;dn[2]=0.0f;
    }

	glBegin(GL_QUADS);
		//glColor3f(0.0f, 0.0f, 0.200f);
		glColor3f(0.152f,0.223f,0.212f);
		glColor3f(up[0],up[1],up[2]);
		glVertex2i(0,695);
		//glColor3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f,0.255f,0.255f);
		glColor3f(dn[0],dn[1],dn[2]);
		glVertex2i(0,440);
		//glColor3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f,0.255f,0.255f);
		glColor3f(dn[0],dn[1],dn[2]);
		glVertex2i(1275,440);
		//glColor3f(0.0f, 0.0f, 0.200f);
		glColor3f(up[0],up[1],up[2]);
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

void TheTitanic(int xinc,int xdec0){

	GLfloat Circlec[]= {1.0f, 1.0f, 1.0f};
	circle(160+xinc,100,28,Circlec);
	circle(270+xinc,100,28,Circlec);
	circle(400+xinc,100,28,Circlec);
	circle(530+xinc,100,28,Circlec);
	circle(670+xinc,100,28,Circlec);

	circle(220+xinc,190,15,Circlec);
	circle(340+xinc,190,15,Circlec);
	circle(460+xinc,190,15,Circlec);
	circle(600+xinc,190,15,Circlec);

	circle(190+xinc,230,15,Circlec);
	circle(245+xinc,230,15,Circlec);
	circle(300+xinc,230,15,Circlec);
	circle(355+xinc,230,15,Circlec);
	circle(410+xinc,230,15,Circlec);
	circle(465+xinc,230,15,Circlec);
	circle(520+xinc,230,15,Circlec);
	circle(575+xinc,230,15,Circlec);

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

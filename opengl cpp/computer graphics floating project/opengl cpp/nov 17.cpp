#include<GL/glut.h>
#include<GL/gl.h>
void display(){
	glClearColor(0.0,0.0,0.0,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(10.0,10.0,0.0);
        glVertex3f(10.0,25.0,0.0);
        glVertex3f(25.0,25.0,0.0);
        glVertex3f(25.0,10.0,0.0);

        glColor3f(1.0,0.0,0.0);
        glVertex3f(10.0,10.0,10.0);
        glVertex3f(10.0,25.0,10.0);
        glVertex3f(25.0,25.0,10.0);
        glVertex3f(25.0,10.0,10.0);
        
        glColor3f(0.0,0.0,1.0);
        glVertex3f(10.0,10.0,0.0);
        glVertex3f(10.0,10.0,10.0);
        glVertex3f(25.0,10.0,10.0);
        glVertex3f(25.0,10.0,0.0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutCreateWindow("Tanvir's First OpenGL");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0,50.0,0.0,50.0,-50.0,50.0);
	glOrtho(0,40,0,40,-40,40);//for work in graph.
    gluPerspective(45.0,1.0,0.0,50.0);

	glutDisplayFunc(display);
    
	glutMainLoop();
	return 0;
}
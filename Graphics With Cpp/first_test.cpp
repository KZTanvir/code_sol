#include<GL/glut.h>
#include<GL/gl.h>
void display(){
	glClearColor(0.0,0.0,0.0,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex2f(5.0f, 5.0f);
		glVertex2f(10.0f, 5.0f);
		glVertex2f(5.0f, 10.0f);

		glColor3f(0.3, 0.2, 0.1);
		glVertex2f(5.0f, 10.0f);
		glVertex2f(10.0f, 10.0f);
		glVertex2f(10.0f, 5.0f);

		glColor3f(0.2, 0.3, 0.1);
		glVertex2f(3.0f, 10.0f);
		glVertex2f(12.0f, 10.0f);
		glVertex2f(7.5f, 14.5f);
	glEnd();
	glFlush();

	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);
    	glVertex2f(10.0f, 10.0f);
    	glVertex2f(5.0f, 5.0f);
    glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutCreateWindow("Tanvir Zamans First Open gl program");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);

	glOrtho(0,20,0,20,-1,1);//for work in graph.

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
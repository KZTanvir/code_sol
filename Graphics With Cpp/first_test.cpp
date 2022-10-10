#include<GL/glut.h>
#include<GL/gl.h>
void display(){
	glClearColor(0.0,0.0,0.0,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		glColor3f(1.0f,0.0f,0.0f); //dont know what type of color it is :p
		glVertex2f(5.0f,5.0f);
		glVertex2f(10.0f,5.0f);
		glVertex2f(10.0f,10.0f);
		glVertex2f(5.0f,10.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
        glColor3f(0.1, 0.2, 0.3);
        glVertex2f(5.0f, 5.0f);
		glVertex2f(10.0f, 5.0f);
		glVertex2f(7.5f, 10.0f);
    glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutCreateWindow("Tanvir Zamans First Open gl program");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);

	glOrtho(0,20,0,20,-1,1);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
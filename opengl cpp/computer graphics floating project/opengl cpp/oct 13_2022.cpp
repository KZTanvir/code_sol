#include<graphics.h>
#include<conio.h>
int main(){

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    circle(100,100,50);
    closegraph();
    getch();
    return 0;
}
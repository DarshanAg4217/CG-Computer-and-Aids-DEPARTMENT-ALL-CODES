#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#include <iostream.h>
#include <stdlib.h> // Include this to fix the error

class walkingman {
public:
    void draw(int);
    void draw(int, int);
};

void walkingman::draw(int i) {
    line(20, 380, 580, 380);
    int base = 25 + i;
    int top = 35 + i;
    line(base, 380, top, 340);
    line(top + 10, 380, top, 340);
    line(top, 310, base, 330);
    delay(20);
    line(top, 340, top, 310);
    circle(top, 300, 10);
    line(top, 310, top + 15, 330);
    line(top + 15, 330, top + 15, 280);
    line(base - 10, 280, top + 50, 280);
    arc(top + 15, 280, 0, 180, 35);
    arc(top + 20, 330, 180, 360, 5);
}

void walkingman::draw(int x, int y) {
    char str[] = "|";
    for(int j = 0; j < 100; j++) {
        outtextxy(rand() % x, rand() % (y - 50), str);
        setcolor(WHITE);
    }
}

void main() {
    int gd = DETECT, gm;
    walkingman obj;
    clrscr();
    cout << "Enter x1 and y1 coordinates: ";
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    for(int i = 0; i < 500; i++) {
        obj.draw(i);
        obj.draw(getmaxx(), getmaxy());
        delay(150);
        cleardevice();
    }
    getch();
    closegraph();
}

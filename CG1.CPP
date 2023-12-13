#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>

void drawcircle(int xc, int yc, int r) {
    int d = 3 - 2 * r;
    int x = 0;
    int y = r;
    while (y >= x) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        delay(50);
    }
}

void drawline(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = dx > dy ? dx : dy;
    float xinc = float(x2 - x1) / float(steps);
    float yinc = float(y2 - y1) / float(steps);
    float x = x1;
    float y = y1;
    for(int k = 0; k < steps; k++) {
        putpixel(x, y, WHITE);
        x = x + xinc;
        y = y + yinc;
    }
}

void main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    int x, y, r;
    int x1, y1, x2, y2, x3;
    cout << "ENTER COORDINATES : ";
    cout << "X1 : ";
    cin >> x1;
    cout << "Y1 : ";
    cin >> y1;
    cout << "X2 : ";
    cin >> x2;
    x3 = (x2 + x1) / 2;
    y2 = y1 - sqrt(pow((x2 - x1), 2) - pow((x2 - x1) / 2, 2));
    drawline(x1, y1, x2, y1);
    drawline(x2, y1, x3, y2);
    drawline(x1, y1, x3, y2);
    x = x3;
    y = y2 + 2 * (y1 - y2) / 3;
    r = (y1 - y2) / 3;
    drawcircle(x, y, r);
    r = 2 * (y1 - y2) / 3;
    drawcircle(x, y, r);
    getch();
    closegraph();
}

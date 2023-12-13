#include<iostream.h>
#include<graphics.h>
#include<conio.h> // Include this for clrscr() and getch()

class Polygon {
public:
    int xavg, yavg;
    void draw(int x1, int y1, int x2, int y2, int x3, int y3) {
        line(x1, y1, x2, y2);
        line(x2, y2, x3, y3);
        line(x3, y3, x1, y1);
        xavg = (x1 + x2 + x3) / 3;
        yavg = (y1 + y2 + y3) / 3;
    }
};

class Triangle : public Polygon {
public:
    void fill(int o_col, int n_col) {
        setfillstyle(SOLID_FILL, n_col);
        floodfill(xavg, yavg, o_col);
    }
};

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    clrscr();
    cout << "\n\t Enter the points of triangle";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    Triangle t;
    t.draw(x1, y1, x2, y2, x3, y3);
    t.fill(WHITE, RED);
    getch(); // Add this line to hold the graphics window open
    closegraph();
    getch(); // Add this line to hold the console window open
    return 0;
}

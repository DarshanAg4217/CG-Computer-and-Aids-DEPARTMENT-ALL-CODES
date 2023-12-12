#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

class Polygon {
public:
    float a[3][3];
    void draw() {
        line(a[0][0],a[1][0],a[0][1],a[1][1]);
        line(a[0][1],a[1][1],a[0][2],a[1][2]);
        line(a[0][2],a[1][2],a[0][0],a[1][0]);
    }
};

class Triangle : public Polygon {
public:
    void transform(float b[3][3]) {
        float c[3][3];
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                c[i][j] = 0;
                for(int k = 0; k<3; k++) {
                    c[i][j] += b[i][k]*a[k][j];
                }
            }
        }
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                a[i][j] = c[i][j];
            }
        }
    }
};

int main() {
    initwindow(1000,800);
    Triangle t;
    cout<<"Enter x1 and y1 coordinates: ";
    cin>>t.a[0][0]>>t.a[1][0];
    cout<<"\nEnter x2 and y2 coordinates: ";
    cin>>t.a[0][1]>>t.a[1][1];
    cout<<"\nEnter x3 and y3 coordinates: ";
    cin>>t.a[0][2]>>t.a[1][2];
    t.a[2][0] = t.a[2][1] = t.a[2][2] = 1;
    t.draw();
    delay(10000);
    cout<<"\n1. Translation \n2. Scaling \n3. Rotation";
    cout<<"\nEnter choice: ";
    int choice;
    cin>>choice;
    float b[3][3] = {0};
    b[0][0] = b[1][1] = b[2][2] = 1;
    switch(choice) {
    case 1:
        cout<<"\nEnter tx and ty: ";
        cin>>b[0][2]>>b[1][2];
        break;
    case 2:
        cout<<"\nEnter sx and sy: ";
        cin>>b[0][0]>>b[1][1];
        break;
    case 3:
        float z;
        cout<<"\nEnter angle: ";
        cin>>z;
        float ang = (z*3.14)/180;
        b[0][0] = cos(ang);
        b[0][1] = sin(ang);
        b[1][0] = -(sin(ang));
        b[1][1] = cos(ang);
        break;
    }
    t.transform(b);
    setcolor(BLUE);
    t.draw();
    getch();  // Add this line
    delay(7000);
    closegraph();
    return 0;
}

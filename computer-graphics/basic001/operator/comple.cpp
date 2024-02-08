#include <iostream>
using namespace std;

class complex{
    float x;
    float y;
    public:
    complex(){}
        void getdata(float real, float imag){
            x = real;
            y = imag;
        }
        complex operator + (complex);
        void display(void);
};

complex complex::operator + (complex c){
    complex temp;
    temp.x = x + c.x;
    temp.y = y + c.y;
    return (temp);
}

void complex::display(void){
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
}

int main(){
    complex c1, c2, c3;
    c1.getdata(3.0, 4.0);
    c2.getdata(5.0, 6.0);
    c3 = c1 + c2;
    c3.display();
    return 0;
}
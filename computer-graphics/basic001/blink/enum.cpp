#include <iostream>

using namespace std;

enum shape
{
    cirlce,
    square,
    triangle
};

int main(){
    cout << "Enter the Shape code";
    int code;
    cin >> code;
    while(code >= cirlce && code <= triangle){
        switch(code){
            case cirlce:
                cout << "This is a cirle";
                break;
            case square:
                cout << "This is a square";
                break;
            case triangle:
                cout << "This is a triangle";
                break;
            default:
                cout << "Enter the right code example, cirle triangle or square";
                break;
            }
            cout << "Enter the shape code";
            cin >> code;
    }
    cout << "bye"
         << "/n";
         
    return 0;
}
#include <iostream>
using namespace std


int main (){
    int i;
    float x ,float sum = 0;
    for (int i = 1; i < 5; i++){
        cout << "Enter a number: ";
        cin >> x;
        sum += x;
    }

    float average;
    average = sum / (i - 1);
    cout << average;
    return 0;

}
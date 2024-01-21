#include <iostream>
using namespace std;

class Person{
    char name[30];
    int age;
    public:
        void getdata(void);
        void display(void);
};

void Person::getdata(void){
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;
}

void Person::display(void){
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
}

int main(){
    Person person1;
    person1.getdata();
    person1.display();
    
    return 0;
}
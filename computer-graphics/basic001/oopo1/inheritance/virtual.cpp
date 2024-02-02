#include <iostream>

using namespace std;

class Student{
    protected:
        int roll_number;

    public:
        void
        get_number(int);
        ;
        void put_number(void);
};

void Student::get_number(int a){
    roll_number = a;
}

void Student::put_number(){
    cout << "Roll Number: " << roll_number << "\n";
}

class Test :virtual public Student{
    protected:
        float sub1;
        float sub2;

    public:
        void get_marks(float,float);
        void put_marks(void);
};

void Test::get_marks(float x,float y){
    sub1 = x;
    sub2 = y;
}

void Test::put_marks(){
    cout << "Marks in Subject 1: " << sub1 << "\n";
    cout << "Marks in Subject 2: " << sub2 << "\n";
}

class Sports :virtual public Student{
    protected:
        float score;

    public:
        void get_score(float);
        void put_score(void);
};

void Sports::get_score(float s){
    score = s;
}

void Sports::put_score(){
    cout << "Sports wt: " << score << "\n";
}

class Result: public Test, public Sports{
    float total;

    public:
        void display(void);
};

void Result ::display(){
    total = sub1 + sub2 + score;
    put_number();
    put_marks();
    put_score();
    cout << "Total: " << total << "\n";
}

int main(){
    Result student1;
    student1.get_number(123);
    student1.get_marks(45.0,60.0);
    student1.get_score(5.0);
    student1.display();
    return 0;
}


#include <iostream>
using namespace std;
class Student{
    private:
        char name[50];
        char grade;
        int roll;
    public:
        Student(char name[],char grade, int roll): name=name[], grade(grade), roll(roll){
            cout<<"In the constructor.";
            }
        void printer(){
            cout<<name;
            cout<<grade;
            cout<<roll;
        }
        };
int main(){
    Student S1("Abhishek",'A',50);
    S1.printer();
}  
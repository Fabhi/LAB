#include <iostream>
using namespace std;
class Student{
    private:
        char name[50];
        char grade;
        int roll;
    public:
        Student(char& n,char g, int r): name(n), grade(g), roll(r){
            cout<<"In the constructor.";
            }
        void printer(){
            cout<<name;
            cout<<grade;
            cout<<roll;
        }
        };
int main(){
    char a[]="Abhishek";
    Student S1(a,'A',50);
    S1.printer();
}  
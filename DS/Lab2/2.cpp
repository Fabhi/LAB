#include <iostream>
#include <stdio.h>
using namespace std;
class Student{
    int rollno;
    char grade;
    char name[50];

    void read(Student a[]){
        int len;
        len=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<len;i++){
            cout<<"Enter the rollno:";
            cin>>a[i].rollno;
            fflush(stdin);
            cout<<"Enter the name:";
            cin>>a[i].name;
            fflush(stdin);
            cout<<"Enter the grade:";
            cin>>a[i].grade;
            fflush(stdin);
        }
    }

    void display(){
        cout<<"Rollno:"<<rollno;
        cout<<"Name:"<<grade;
        cout<<"Grade:"<<name;
    }
};

int main(){
    Student s[10];
    s.read();
    //This is better
    
}
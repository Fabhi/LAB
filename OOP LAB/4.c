//Program to create a student structure
#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float marks;
} stud[100];

void grade(int mark){
    if(mark>90 && mark<=100){
        printf("A Grade Obtained\n");}
    else if(mark>80){
        printf("A Grade Obtained\n");}
    else if(mark>70){
        printf("B Grade Obtained\n");}
    else if(mark>60){
        printf("C Grade Obtained\n");}
    else if(mark>50){
        printf("D Grade Obtained\n");}
    else if(mark<50){
        printf("F Grade Obtained\n");}
    else {
        printf("Invalid Marks entered to calulate Grade\n");}
}

void main()
{
    int i,n;
    printf("Enter number of students:\n");
    scanf("%d", &n);
    for(i=0; i<n; ++i)
    {
        stud[i].roll = i+1;
        printf("For roll number%d,\n",stud[i].roll);
        printf("Enter name: ");
        scanf("%stud",stud[i].name);
        printf("Enter marks: ");
        scanf("%f",&stud[i].marks);
        printf("\n");
    }
    printf("Displaying Information:\n");
    for(i=0; i<n; ++i)
    {
        printf("Roll number: %d\n",i+1);
        printf("Name: ");
        puts(stud[i].name);
        printf("Marks: %.1f",stud[i].marks);
        printf("\n");
        grade(stud[i].marks);
    }
}
 
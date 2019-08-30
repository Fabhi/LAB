import java.util.Scanner;
class Student{
    Scanner scan= new Scanner(System.in);
    int regno;
    String name;
    int age;
    int marks[]=new int[3];
    char grade;
    Student(){
        System.out.println("Enter the name of the student:");
        this.name = scan.nextLine();
        System.out.println("Enter the registration number of the student:");
        this.regno = scan.nextInt();
        System.out.println("Enter the age of the student:");
        this.name = scan.nextLine();
    }

    void dispGrade(){
        System.out.println("Marks obtained:");
        for(int i:marks){
            System.out.println(i);
        }
        System.out.println("Grade Obtained: "+grade);
    }
};

class UG{
    UG(){
        super();
        System.out.println("Enter the marks:");
        for(int i:marks){
            System.out.println(i);
        }
        calcGrade();
    }
    void calcGrade(){
        
    }
}
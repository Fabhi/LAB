package ObjectComp;


// Sorting objects using toString method
class Student{
    int ID;
    String name;
    Student(String n, int i){
        name=n;
        ID=i;

    }

    public String toString(){
        return name+" "+ID; 
    }
}

public class Main{

    static void compare(Student[] s){
        for(int i=0;i<s.length;i++){
            for(int j=0;j<s.length-i-1;j++){
                if((s[j]+"").compareTo(s[j+1]+"")>0){
                    Student temp=s[j];
                    s[j]=s[j+1];
                    s[j+1]=temp;
                }
            }
        }
    }
    public static void main(String[] args){
        Student[] s= new Student[4];
        s[0]= new Student("Abhiram", 23);
        s[1]= new Student("Viram", 2);
        s[2]= new Student("Parrot",56);
        s[3]= new Student("Parrot",23);
        for(int i=0;i<4;i++)
            System.out.println(s[i]);
        compare(s);
        for(int i=0;i<4;i++)
            System.out.println(s[i]);
    }
}
import java.io.*;
import java.text.SimpleDateFormat;
import java.util.*;

class Sorter extends Thread{
    Author[] a;
    Author temp;
    int choice;
    Sorter(Author[] a, int choice){
        this.a=a;
        this.choice=choice;
    }
    public void run(){
        if(choice==1){
            for(int i=0;i<a.length-1;i++){
                for(int j=0;j<a.length-i-1;j++){
                    if(a[j+1].city.compareTo(a[j].city)>0){
                        temp=a[j+1];
                        a[j+1]=a[j];
                        a[j]=temp;
                    }
                }
            }
        }
        else if(choice==2){
            SimpleDateFormat sdf= new SimpleDateFormat("DD-MM-YYYY");
            for(int i=0;i<a.length-1;i++){
                for(int j=0;j<a.length-i-1;j++){
                    try{
                        if(sdf.parse(a[j].dob).before(sdf.parse(a[j+1].dob))){
                            temp=a[j+1];
                            a[j+1]=a[j];
                            a[j]=temp;
                        }
                    }
                    catch(Exception e){
                        System.out.println(e);
                    }   
                }
            }
        }
        else{
            System.out.println("Invalid Choice!");
        }
    }
}


class Author implements Serializable{
    static final long serialVersionUID=1L;
    String name, city, dob;
    int authorId;
    Author(){
        Scanner scan=new Scanner(System.in);
        System.out.println("Name:");
        name=scan.nextLine();
        System.out.println("DOB(DD-MM-YYYY)");
        dob=scan.nextLine();
        System.out.println("AuthorID");
        authorId=scan.nextInt();
        scan.nextLine();
        System.out.println("City");
        city=scan.nextLine();
    }
    public String toString(){
        return name+" "+dob+" "+authorId+" "+city;
    }
}



class InvalidChar extends Exception{
    public String toString(){
        return "INVALID CHARACTER ENTERED!";
    }
}



class Book implements Serializable{
    static final long serialVersionUID=2L;
    int ISBN;
    String author, name, publish;
    char tech;
    Book(){
        Scanner scan=new Scanner(System.in);
        System.out.println("Name:");
        name=scan.nextLine();
        try{
            if(Check(name))
            throw new InvalidChar();
        }
        catch(InvalidChar c){
            System.out.println(c);
        }
        System.out.println("Author:");
        author=scan.nextLine();
        System.out.println("Date of Publishing(DD-MM-YYYY)");
        publish=scan.nextLine();
        System.out.println("ISBN");
        ISBN=scan.nextInt();
        scan.nextLine();
        System.out.println("Technical? Y/N");
        tech=scan.nextLine().charAt(0);
    }

    static boolean Check(String name){
        for(int i=0;i<name.length();i++){
            char c=name.charAt(i);
            if(!((c>='A'&& c<='Z')||(c>='a' && c<='z')||(c>='0'&&c<='9'))){
                return true;
            }
        }
        return false;
    }
}



public class Main{
    
    static String vowels(String input){
        StringBuffer output= new StringBuffer();
        for(int i=0;i<input.length();i++){
            char c=input.charAt(i);
            switch(c){
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    output.append(c);
            }
        }
        return output.toString();
    }
    public static void main(String args[]) throws Exception{
        File f1=new File("Author.txt");
        File f2=new File("Book.txt");
        f1.createNewFile();
        f2.createNewFile();
        Author[] a;
        Book[] b;


        Scanner scan=new Scanner(System.in);
        System.out.println("Enter number of entries for authors");
        int n=scan.nextInt();
        scan.nextLine();
        a= new Author[n];
        for(int i=0;i<n;i++){
            a[i]=new Author();
        }
        System.out.println("Enter number of entries for books:");
        n=scan.nextInt();
        b= new Book[n];
        for(int i=0;i<n;i++){
            b[i]=new Book();
        }


        ObjectOutputStream oos1= new ObjectOutputStream(new FileOutputStream(f1));
        ObjectOutputStream oos2= new ObjectOutputStream(new FileOutputStream(f2));
        oos1.writeObject(a);
        oos2.writeObject(b);
        oos1.close();
        oos2.close();
        scan.close();
        ObjectInputStream ois1= new ObjectInputStream(new FileInputStream(f1));
        ObjectInputStream ois2= new ObjectInputStream(new FileInputStream(f2));
        a=(Author[])ois1.readObject();
        b=(Book[])ois2.readObject();
        ois1.close();
        ois2.close();

        for(int i=0;i<a.length;i++){
            int entries=0;
            for(int j=0;j<b.length;j++){
                if(a[i].name.compareTo(b[j].author)==0)
                    entries+=1;
            }
            if(entries>=3)
                System.out.println(a[i].name);
        }


        for(int i=0;i<b.length;i++){
            for(int j=0;j<b.length;j++){
                if(b[j].author==b[i].author && j!=i)
                    System.out.println(vowels(b[j].name));
            }
        }


        System.out.println("Before Sorting");
        for(int i=0;i<a.length;i++)
        System.out.println(a[i]);
        System.out.println("------------------------");
        Sorter s1= new Sorter(a,1);
        s1.start();
        s1.join();
        System.out.println("After Sorting by City");
        for(int i=0;i<a.length;i++)
        System.out.println(a[i]);
        System.out.println("------------------------");
        Sorter s2= new Sorter(a,2);
        s2.start();
        s2.join();
        System.out.println("After sorting by DOB");
        for(int i=0;i<a.length;i++)
        System.out.println(a[i]);
        System.out.println("------------------------");
    }
}
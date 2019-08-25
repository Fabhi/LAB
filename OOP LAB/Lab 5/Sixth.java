import java.io.FileInputStream;
import java.util.Scanner;
class Book{
    String title, author, edition;
    Book(String s1, String s2, String s3){
        this.title=s1;
        this.author=s2;
        this.edition=s3;
    }
    void write(){
    FileInputStream f= new FileInputStream("Books.txt");
    
    }
}
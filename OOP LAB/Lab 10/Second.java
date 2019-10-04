import java.util.Scanner;
import java.io.*;

public class Second{
    public static void main(String args[]) throws IOException, EOFException{
        Scanner scan= new Scanner(System.in);
        RandomAccessFile f1= new File("Second.txt",rw);
        if(!f1.exists())
            f1.createNewFile();
        
    }
}
/*1.Read a 3x3 word/string matrix from a file
2. In a thread called EvenThread 
    Rearrange the words in the first and third columns reverse alphabetically. Output them to a new file (also reverse alphabetically).
    If a word in the 2nd column occurs in either the first and second column,
    throw a user defined exception DuplicateWordFound that prints "Duplicate word" + word
3. In a thread called secondarythread
    Ask the user for an input for a word.
    If the word occurs in the secondary diagonal,replace the word with the alphabetical rearrangement of it. 
    If it is not present in the secondary diagonal throw a KeywordNotFound exception */


import java.io.*;
import java.util.*;

import org.w3c.dom.events.EventException;

class DuplicateWordFound extends Exception{
    String word;
    DuplicateWordFound(String s){
        word=s;
    }
    public String toString(){
        return "DuplicateWord "+word;
    }
}

class KeywordNotFound extends Exception{
    public String toString(){
        return "KeywordNotFound";
    }
}

class EvenThread extends Thread{
    String[][] str;
    EvenThread(String[][] s){
        str=s;
        this.start();
    }
    static void printer(String[][] str){
        for(int i=0;i<str.length;i++){
            for(int j=0;j<str[i].length;j++){
                System.out.print(str[i][j]+" ");
            }
            System.out.println();
        }
    }
    public void run(){
        String n[][]= new String[3][3];
        try{
            ObjectOutputStream oos= new ObjectOutputStream(new FileOutputStream("Words2.txt"));
            for(int i=0;i<3;i+=2){
                for(int j=0;j<3;j++){
                    n[i][j]=(new StringBuffer(str[i][j])).reverse().toString();
                }
                Arrays.sort(n[i]);
                oos.writeObject(n[i]);
            }
            printer(n);
        }
        catch(Exception e){
            System.out.println(e);
        }

        try{
            for(String s:str[1]){
                for(String m:str[0]){
                    if(s.equals(m))
                        throw new DuplicateWordFound(s);
                }
                for(String m:str[2]){
                    if(s.equals(m))
                        throw new DuplicateWordFound(s);
                }
            }
        }
        catch(DuplicateWordFound d){
            System.out.println(d);
        }
    }
}

class SecondaryThread extends Thread{
    String[][] s;
    SecondaryThread(String[][] s){
        this.s=s;
        this.start();
    }
    static String replace(String s){
        String output;
        byte a[]= new byte[s.length()];
        for(int i=0;i<s.length();i++){
            a[i]=(byte) s.charAt(i);
        }
        Arrays.sort(a);
        output=new String(a);
        return output;
    }
    public void run(){
        boolean found =false;
        Scanner scan= new Scanner(System.in);
        System.out.println("Enter a word");
        String match= scan.nextLine();
        for(int i=0;i<3;i++){
            if(s[1][i].equals(match)){
                s[1][i]=replace(s[1][i]);
                found=true;
            }
        }
        try{
            if(!found)
                throw new KeywordNotFound();
        }
        catch(KeywordNotFound e){
            System.out.println(e);
        }
    }
}

public class Main{
    static void printer(String[][] str){
        for(int i=0;i<str.length;i++){
            for(int j=0;j<str[i].length;j++){
                System.out.print(str[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String args[]) throws Exception{
        String[][] str= new String [3][3];
        Scanner scan= new Scanner(System.in);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                str[i][j]=scan.nextLine();
            }
        }
        ObjectOutputStream oos= new ObjectOutputStream(new FileOutputStream("Words.txt"));
        oos.writeObject(str);
        oos.close();

        ObjectInputStream ois= new ObjectInputStream(new FileInputStream("Words.txt"));
        String[][] str2= (String[][])ois.readObject();
        printer(str2);

        EvenThread t1= new EvenThread(str2);
        SecondaryThread t2= new SecondaryThread(str2);
        t1.join();
        t2.join();
        printer(str2);
    }

}
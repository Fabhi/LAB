// Create a java program which will take geeks for geeks as the input and does the following:
// Replace all occurences of e with a
// Return the substring between 2nd to 6th Position
// Make the first alphabet capital of each word in the given string 
import java.util.Scanner;
public class Eval{
    public static void main(String args[]){
        Scanner scan= new Scanner(System.in);
        System.out.print("Enter the string:");
        String s= scan.nextLine();
        System.out.println(s.replace('e','a'));
        System.out.println(s.substring(2,6));
        System.out.println(s.replace('g','G').replace('f', 'F'));
        System.out.println(s.replace('g','G'));
        System.out.println(s.replace('f', 'F'));
        StringBuffer sb= new StringBuffer(s);
        sb.setCharAt(0,(char)(sb.charAt(0)-32));
        for(int i=0;i<sb.length();i++){
            if(sb.charAt(i)==' '){
                if(i+1<sb.length()){
                    sb.setCharAt(i+1,(char)(sb.charAt(i+1)-32));
                }
            }
        }
        System.out.println(sb);
        scan.close();
        // String s2= "s3"+(123+456);
        // String s1= "s3"+123+456;
        // String s1= "Abh";
        // System.out.println(s1=s2);
    }
}
import java.util.Scanner;
public class Third{
    static void sorting(StringBuffer s){
        char c;
        String s1=s.toString();
        for(int i=0;i<s1.length();i++){
            for(int j=i+1;j<s1.length();i++){
                if(s.charAt(i)>s1.charAt(j)){
                    c=s.charAt(i);
                    s1.replace(s.charAt(i),s.charAt(j));
                    s1.replace(s.charAt(j),c);
                }
            }
        }
        System.out.println(s1);
    }
    public static void main(String aargs[]){
        System.out.print("Enter string:");
        Scanner scan= new Scanner(System.in);
        StringBuffer sb= new StringBuffer();
        StringBuffer s=new StringBuffer(scan.nextLine());
        sb.append(s);
        sb.reverse();
        if(sb.toString().equals(s.toString()))
            System.out.println("String is a palindrome");
        else
            System.out.println("Not a palindrome");
        sorting(s);
    }
}
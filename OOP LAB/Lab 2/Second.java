import java.util.Scanner;
public class Second{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int i= scan.nextInt();
        double d= scan.nextDouble();
        char c= scan.next().charAt(0);
        System.out.println(i);
        System.out.println(d);
        System.out.println(c);
        scan.close()
    }
}
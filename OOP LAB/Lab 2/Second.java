import java.util.Scanner;
public class Second{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int i= scan.nextInt();
        double d= scan.nextDouble();
        char c= scan.next().charAt(0);
        byte b= (byte) i;
        int ii= (int) c;
        byte db=(byte) d;
        int di =(int) i; 
        System.out.println(i);
        System.out.println(d);
        System.out.println(c);
        System.out.println(b);
        System.out.println(ii);
        System.out.println(db);
        System.out.println(di);
        scan.close();
    }
}
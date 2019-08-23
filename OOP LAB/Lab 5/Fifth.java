import java.util.Scanner;
class Number{
    double d1;
    Number(double d){
        this.d1=d;
    }
    boolean isZero(){
        boolean b=true;
        if(d1== 0.0)
            return true;
        return !b;
    }
    boolean isPositive(){
        boolean b=true;
        if(d1>0)
            return b;
        return !b;
    }
    boolean isNegative(){
        boolean b=true;
        if(d1<0)
            return b;
        return !b;
    }
    boolean isOdd(){
        boolean b=true;
        if(d1%2.0!=0)
            return b;
        return !b;
    }
    boolean isEven(){
        boolean b=true;
        if(d1%2.0==0)
            return b;
        return !b;
    }
    boolean isPrime(){
        boolean b=true;
        return b;
    }
    boolean isArmstrong(){
        boolean b=true;
        return b;
    }
}

public class Fifth{
    public static void main(String args[]){
        Number n1 =new Number(-3.0);
        System.out.println(n1.isEven());
        System.out.println(n1.isOdd());
        System.out.println(n1.isNegative());
        System.out.println(n1.isPositive());
        System.out.println(n1.isZero());
    }
}
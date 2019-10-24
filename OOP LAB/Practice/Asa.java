class EvenNumber extends Exception{
    int a;
    EvenNumber(int n)
    {
        a=n;
        System.out.println("inside constructor");
    }
    public String toString()
    {
        System.out.println("Inside toString");
        return "You entered an even number "+a;
    }
}

public class Asa{
    public static void main(String args[])
    {
        int n = Integer.parseInt(args[1]);
        try{
            System.out.println(n);
            if(n%2==0)
            {
                throw new EvenNumber(n);
            }   
            System.out.println("Odd:"+n);
        }
        catch(EvenNumber e)
        {
            System.out.println("a"+e);
        }
        finally
        {
            System.out.println("exiting");
        }
    }
}
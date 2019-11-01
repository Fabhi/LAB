class ThreadDemo extends Thread{
    String name;
    ThreadDemo(String named){
        super(named);
        name=named;
    }
    public void run(){
        synchronized(this){
            for(int i=0;i<5;i++)
            System.out.println(getName()+" :"+i);
        }
    }
}

public class Thread1{
    public static void main(String args[]){
        Thread t=Thread.currentThread();
        Thread t1=new ThreadDemo("Child 1");
        Thread t2=new ThreadDemo("Child 2");
        Thread t3=new ThreadDemo("Child 3");
        System.out.println("Parent Thread"+t);
        t.setName("Parent");
        System.out.println("Parent Thread"+t);
        t1.start();
        t2.start();
        t3.start();
        try{
            t1.join();
            t2.join();
            t3.join();
        }
        catch(InterruptedException e){
            System.out.println("Thread Error");
        }
        System.out.println("Exiting Main Thread");
    }
}
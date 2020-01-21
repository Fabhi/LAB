class ThreadRipper extends Thread{
    int n;
    ThreadRipper(int n){
        this.n=n;
        System.out.println("Initiating Thread!");
        start();
    }
    public void run(int n){
        for(int i=0;i<n;i++){
            System.out.println(i);
        }
    }
}

class Threader implements Runnable{
    int n;
    Thread t;
    Threader(){
        t= new Thread(this,"Example");
        t.start();
    }
    
}
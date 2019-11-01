import java.util.Scanner;
class Summer implements Runnable{
    Thread t;
    int flag;
    int[][] arr;
    int sum;
    Summer(String name,int[][] arr, int flag){
        t= new Thread(this,name);
        this.arr=arr;
        this.flag=flag;
    }
    public void run(){
        int n=arr.length;
        System.out.println("Inside!");
        if(flag==-1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    sum+=arr[i][j];
                }
            }
        }
        else if(flag==0){
            for(int i=0;i<n;i++){
                sum+=arr[i][i];
            }
        }
        else if(flag==1){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    sum+=arr[j][i];
                }
            }
        }
        else{
            System.out.println("Wrong flag!");
        }
    }
}

public class Diagonal{
    public static void main(String args[]){
        Scanner scan=new Scanner(System.in);
        int n=scan.nextInt();
        scan.nextLine();

        int arr[][]= new int[n][n];
        System.out.println("Enter array:");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j]=scan.nextInt();
            }
        }
        
        Summer t1= new Summer("Child 1",arr,-1);
        Summer t2= new Summer("Child 2",arr, 0);
        Summer t3= new Summer("Child 3",arr, 1);
        t1.t.start();
        t2.t.start();
        t3.t.start();
        try{
            t1.t.join();
            t2.t.join();
            t3.t.join();
        }
        catch(InterruptedException e){
            System.out.println(e);
        }
        int sum=t1.sum + t2.sum + t3.sum;
        System.out.println(sum);
    }
}
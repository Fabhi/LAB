#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Task{
    public:
    int start,finish;
};
bool Comparetasks(Task t1,Task t2){
    return(t1.start<t2.start);
}
void printtasks(Task arr[],int n){
    sort(arr,arr+n,Comparetasks);
    bool selected[n]= {false};
    int used=0;
    // 'i' is a new machine
    for(int i=0;i<n;i++){
        if(selected[i])
            continue;
        cout<<"========================================";
        cout<<"\n"<<"Task Allocation For Machine :"<<used+1<<"\n";
        cout<<"("<<arr[i].start<<","<<arr[i].finish<<")"<<"\n";
        selected[i]=1;
        // 'j' handles the old machine finding new jobs
        for(int j=i+1;j<n;j++){
            if(selected[j])
                continue;
            if(arr[i].finish<=arr[j].start){
                i=j;
                selected[j]=1;
                cout<<"("<<arr[j].start<<","<<arr[j].finish<<")"<<"\n";
            }
        }
        // Bring i back to the original value and increment used(i is incremented by the loop)
        i=used++;
    }
    cout<<"\n"<<"Total Machines Used "<<used;
}
int main(){
    Task arr[10];
    int n;
    cout<<"Enter the number of Tasks";
    cin>>n;
    cout<<"Enter Start and Finish time of each machine";
    for(int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish;
    printtasks(arr,n);
    return 0;
}
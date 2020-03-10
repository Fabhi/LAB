// Program to implement QuickSort
// TODO: Write the recurrence relation using Master's Theorem in manual
#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(int arr[],int beg, int end){
    int loc=beg;
    int left=beg;
    int right=end;
    bool sorted=false;
    while(!sorted){
        while(loc!=right && arr[loc]<=arr[right])
            right--;
        if(loc==right)
            sorted=true;
        else if(arr[loc]>arr[right]){
            swap(arr[loc],arr[right]);
            loc=right;
        }
        //This block only runs if the right side is sorted
        if(!sorted){
            while(arr[loc]>=arr[left] && loc!=left)
                left++;
            if(loc==left)
                sorted=true;
            else if(arr[loc]<arr[left]){
                swap(arr[loc],arr[left]);
                loc = left;
            }
        }
    }
    return loc;
}

void QuickSort(int arr[],int beg, int end){
    int loc;
    if(beg<end){
        loc=partition(arr,beg,end);
        QuickSort(arr,beg, loc-1);
        QuickSort(arr,loc+1,end);
    }
}

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    print(arr,n);
    QuickSort(arr,0,n-1);
    print(arr,n);
}
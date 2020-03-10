#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int, int> getminmax(int a[],int low,int high){
	pair<int,int> minmax;
	if(low==high){
		minmax.first=a[low];
		minmax.second=a[low];
		return minmax;
	}

	if(high==low+1){
		if(a[low]>a[high]){
			minmax.second=a[low];
			minmax.first=a[high];
		}	
		else{
			minmax.second=a[high];
			minmax.first=a[low];
		}
	return minmax;
	}

	int mid=(low+high)/2;
    pair<int, int> ml=getminmax(a,low,mid);
	pair<int, int> mr=getminmax(a,mid+1,high);

	if(ml.first<mr.first)
		minmax.first=ml.first;
	else
		minmax.first=mr.first;
	if(ml.second<mr.second)
		minmax.second=mr.second;
	else
		minmax.second=ml.second;
	return minmax;
}

int main(){
	int n;
	cout<<"Enter size:";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
          cin>>a[i];
	pair<int,int> minmax = getminmax(a,0,n-1);
	cout<<"\nMinimum element is : "<<minmax.first; 
 	cout<<"\nMaximum element is : "<<minmax.second;
}


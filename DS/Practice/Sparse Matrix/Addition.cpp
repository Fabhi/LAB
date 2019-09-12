//Program to implement the addition of Sparse Matrix
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Sparse{
    private:
    int row, column, value;
    public:
    Sparse(){}
    Sparse(int r, int c, int v): row(r), column(c), value(v){}
    void set(int r, int c, int v){
        row=r;
        column=c;
        value=v;
    }
};

int main(){
    int m,n;
    cout<<"Enter the size of the matrix 1:"<<endl;
    cin>>m>>n;
    int arr1[m][n];
    int count1=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter ["<<i<<"]["<<j<<"]:";
            cin>>arr1[i][j];
            if(arr1[i][j]!=0)
                count1++;
        }
    }
    //Developing a sparse matrix
    Sparse s[count1+1];
    s[0].set(m,n,count1);
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr1[i][j]!=0){
                s[++k].set(i,j,arr1[i][j]);
            }
        }
    }
}
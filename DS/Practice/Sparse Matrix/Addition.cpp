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

int input(int arr[][], int m, int n){
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<"Enter ["<<i<<"]["<<j<<"]:";
            cin>>arr[i][j];
            if(arr[i][j]!=0)
                count++;
        }
    }
    return count;
}

void Sparsify(Sparse s[], int count,int arr[][], int m, int n){
    s[0].set(m,n,count);
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=0){
                s[++k].set(i,j,arr[i][j]);
            }
        }
    }
}
int main(){
    //MATRIX 1
    int m,n;
    cout<<"Enter the size of the matrix 1:"<<endl;
    cin>>m>>n;
    int arr[m][n];
    int count=input(arr,m,n);
    //Developing a sparse matrix
    Sparse a[count+1];
    Sparsify(a,count,arr, m,n);
    //MATRIX 2
    int m,n;
    cout<<"Enter the size of the matrix 2:"<<endl;
    cin>>m>>n;
    int arr2[m][n];
    int count=input(arr2,m,n);
    //Developing a sparse matrix
    Sparse b[count+1];
    Sparsify(b,count,arr2, m,n);

}
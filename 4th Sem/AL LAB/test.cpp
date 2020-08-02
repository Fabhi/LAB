#include <bits/stdc++.h>
using namespace std;

int f(int W, int wt[], int val[], int i, int **dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];

    if (wt[i] > W || wt[i] % 2 != 0)
    {
        dp[i][W] = f(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else
    {
        dp[i][W] = max(val[i] + f(W - wt[i], wt, val, i - 1, dp), f(W, wt, val, i - 1, dp));
        return dp[i][W];
    }
}

int knapSack(int W, int wt[], int val[], int n)
{
    int **dp;
    dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    int a= f(W, wt, val, n - 1, dp);
       for(int i=0;i<n;i++){
        for(int j=0;j<W+1;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return a;
}

int main()
{
    int i, n;
    cout << "Enter number of items: ";
    cin >> n;
    int val[n];
    int wt[n];
    cout << "Enter profit array: " << endl;
    for (i = 0; i < n; i++)
        cin >> val[i];
    cout << "Enter weights array: " << endl;
    for (i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter capacity: ";
    int W;
    cin >> W;
    cout << knapSack(W, wt, val, n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int f(int m,int n,vector<vector<int>> &dp){
    /*Recurrsion*/ //TC = 2^(m*n); SC = path travelled
    // if(i==0 && j==0)
        //     return 1;
        // if(i<0||j<0)
        //     return 0;
        // int up = f(i-1,j);
        // int left = f(i,j-1);
        // return up+left;
    
    /*Memoization*///TC = m*n; SC = path length + dp size
    // if(i==0&&j==0){
    //     return dp[i][j]=1;
    // }
    // if(i<0||j<0) return 0;
    // if(dp[i][j]!=-1) return dp[i][j];
    // int up = f(i-1,j,dp);
    // int left = f(i,j-1,dp);
    // return dp[i][j]=(up+left);

    /*Tabulation*/
    // for(int a=0;a<i;a++){
    //     for(int b=0;b<j;b++){
    //         if(a==0&&b==0) dp[a][b]=1;
    //         int up=0,left=0;
    //         if(a>0) up = dp[a-1][b];
    //         if(b>0) left = dp[a][b-1];
    //         dp[a][b]= up+left;
    //     }
    // }
    // return dp[i-1][j-1];

    /*Space Optimization*/
    vector<int>prev(n,0);
        for(int a=0;a<m;a++){
            vector<int> temp(n,0);
            for(int b=0;b<n;b++){
                if(a==0&&b==0){
                    temp[b]=1;
                }
                else{
                    int up=0,left=0;
                    if(a>0) up = prev[b];
                    if(b>0) left = temp[b-1];
                    temp[b] = up + left;
                }
            }
            prev = temp;
        }
        return prev[n-1];
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    int count = f(m-1,n-1,dp);
    cout<<dp[m-1][n-1]<<endl;
}
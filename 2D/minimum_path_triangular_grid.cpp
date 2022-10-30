#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
    /*Recurrsive approach*///TC = 2^sum of states
    // if(n==grid.size()-1) return grid[n][m];
    // int down = grid[n][m]+f(n+1,m,grid);
    // int diagonal= grid[n][m]+f(n+1,m+1,grid);
    // return min(down,diagonal);

    /*Memoization*///TC = n*n ; SC=n*n + n
    // if(n==grid.size()-1) return dp[n][m]=grid[n][m];
    // if(dp[n][m]!=-1) return dp[n][m];
    // int down = grid[n][m]+f(n+1,m,grid,dp);
    // int diagonal= grid[n][m]+f(n+1,m+1,grid,dp);
    // return dp[n][m]=min(down,diagonal);

    /*Tabulisation*/
    // for(int j=0;j<n;j++){
    //         dp[n-1][j] = grid[n-1][j];
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int down = grid[i][j]+dp[i+1][j];
    //             int diagonal= grid[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(down,diagonal);
    //         }
    //     }
    //     return dp[0][0];

    /*Space Optimized*///TC = n*n ; SC = 2*n
    vector<int> d(n,-1);
        for(int j=0;j<n;j++){
            d[j] = grid[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=i;j>=0;j--){
                int down = grid[i][j]+d[j];
                int diagonal= grid[i][j]+d[j+1];
                temp[j]=min(down,diagonal);
            }
            d=temp;
        }
        return d[0];
}



int main(){
    int n; cin>>n;
    vector<vector<int>> a;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<i+1;j++){
            int val;cin>>val;
            temp.push_back(val);
        }
        a.push_back(temp);
    }
    vector<vector<int>>dp(n,vector<int>(n,-1));
    int value =f(0,0,a,dp);
    cout<<value<<endl;
}
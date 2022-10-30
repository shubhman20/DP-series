#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,vector<vector<int>> &grid,vector<vector<int>>&dp){
    /*Recurrsive solution*/ //TC = 
    // if(n==0&&m==0) return grid[0][0];
    // if(n<0||m<0) return 1e9;
    // int up = f(n-1,m,grid);
    // int left = f(n,m-1,grid);
    // return min(up,left);

    /*Memoization*/
    // if(m==0&&n==0){
    //         return dp[0][0]=grid[0][0];
    //     }
    //     if(m<0||n<0){
    //         return 1e9;
    //     }
    //     if(dp[m][n]!=-1) return dp[m][n];
    //     int up = f(m-1,n,grid,dp)+grid[m][n];
    //     int left = f(m,n-1,grid,dp)+grid[m][n];
    //     return dp[m][n]=min(up,left);

    /*Tabulation*/
    // for(int i=0;i<grid.size();i++){
    //         for(int j=0;j<grid[0].size();j++){
    //             if(i==0&&j==0){
    //                 dp[0][0]=grid[0][0];
    //                 continue;
    //             }
    //             int up = 1e9;
    //             int left = 1e9;
    //             if(i>0) up = grid[i][j]+dp[i-1][j];
    //             if(j>0) left = grid[i][j]+dp[i][j-1];
    //             dp[i][j]=min(up,left);
    //         }
    //     }
    //     return dp[grid.size()-1][grid[0].size()-1];

    /*Space Optimization*/
    vector<int> d(grid[0].size(),0);
        for(int i=0;i<grid.size();i++){
            vector<int> temp(grid[0].size());
            for(int j=0;j<grid[0].size();j++){
                if(i==0&&j==0){
                    temp[0]=grid[0][0];
                    continue;
                }
                int up = 1e9;
                int left = 1e9;
                if(i>0) up = grid[i][j]+d[j];
                if(j>0) left = grid[i][j]+temp[j-1];
                temp[j]=min(up,left);
            }
            d=temp;
        }
        return d[grid[0].size()-1];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    vector<vector<int>>dp(n,vector<int>(m,0));
    int count = f(n-1,m-1,grid,dp);
    cout<<count<<endl;
}
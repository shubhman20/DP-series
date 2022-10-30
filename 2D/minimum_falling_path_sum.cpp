#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,vector<vector<int>> &matrix,vector<vector<int>>& dp){
        
        /*Recurrsive Approach*///TC = 3^n; SC = n
        // if(n<0 || m<0 || n>=matrix.size()||m>=matrix[n].size()) return 1e9;
        // if(n==0) return matrix[n][m];
        // int up = f(n-1,m,matrix)+matrix[n][m];
        // int diagr = f(n-1,m+1,matrix) +matrix[n][m];
        // int diagl =f(n-1,m-1,matrix)+matrix[n][m];
        // return min(up,min(diagr,diagl));

        /*Memoization*///TC = n*m; SC = n*m + n
        // if(n<0 || m<0 || n>=matrix.size()||m>=matrix[n].size()) return 1e9;
        // if(n==0) return matrix[n][m];
        // if(dp[n][m]!=-1) return dp[n][m];
        // int up = f(n-1,m,matrix,dp)+matrix[n][m];
        // int diagr = f(n-1,m+1,matrix,dp) +matrix[n][m];
        // int diagl =f(n-1,m-1,matrix,dp)+matrix[n][m];
        // return dp[n][m]=min(up,min(diagr,diagl));
        
        /*Tabulisation*///TC = n*m + m ; SC = n*m
        // for(int i=0;i<m;i++){
        //     dp[0][i] = matrix[0][i];
        // }
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int up=1e9,diagr=1e9,diagl=1e9;
        //         up = matrix[i][j]+dp[i-1][j];
        //         if(j>0) diagl = matrix[i][j]+dp[i-1][j-1];
        //         if(j+1<m) diagr = matrix[i][j]+dp[i-1][j+1];
        //         dp[i][j] = min(up,min(diagl,diagr));
        //     }
        // }
        // int mini = INT_MAX;
        // for(int i=0;i<m;i++){
        //     mini = min(mini,dp[n-1][i]);
        // }
        // return mini;

        /*Space optimisation*///TC = n*m; SC= m
        vector<int>d(n,-1);
        for(int i=0;i<m;i++){
            d[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(m,0);
            for(int j=0;j<m;j++){
                int up=1e9,diagr=1e9,diagl=1e9;
                up = matrix[i][j]+d[j];
                if(j>0) diagl = matrix[i][j]+d[j-1];
                if(j+1<m) diagr = matrix[i][j]+d[j+1];
                temp[j] = min(up,min(diagl,diagr));
            }
            d=temp;
        }
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini,d[i]);
        }
        return mini;
    }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    int temp=1e9;
    vector<vector<int>>dp(n,vector<int>(m,-1));
    // for(int i=0;i<grid[n-1].size();i++){
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //         int val = f(n-1,i,grid,dp);
    //         temp = min(temp,val);
    //     }
    temp = f(n-1,m-1,grid,dp);
    cout<<temp<<endl;
}
#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> a,int sum,int idx,vector<vector<int>>&dp){
    /*Recurrsive Approach*///TC = 2*n ; SC= n
    // if(sum==0) return true;
    // if(idx==0) return (a[0]==sum);
    // bool notTake = f(a,sum,idx-1);
    // bool take =false;
    // if(sum>=a[idx]){
    //     take = f(a,sum-a[idx],idx-1);
    // }
    // return (take||notTake);

    /*Memoization*///TC = n*target ; SC = n*target + n
    // if(sum==0) return true;
    //     if(idx==0) return (a[0]==sum);
    //     if(dp[idx][sum]!=-1) return dp[idx][sum];
    //     bool notTake = f(a,sum,idx-1,dp);
    //     bool take =false;
    //     if(sum>=a[idx]){
    //         take = f(a,sum-a[idx],idx-1,dp);
    //     }
    //     return dp[idx][sum]=(take||notTake);

    /*Tabulation*/
    

}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum;
    cin>>sum;
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    bool val = f(a,sum,n-1,dp);
    cout<<val<<endl;
}
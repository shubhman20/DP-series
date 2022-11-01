#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> a,int sum,int idx,vector<vector<bool>>&dp){
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

    /*Tabulation*///TC= n*sum SC = n*sum
    // for(int i=0;i<a.size();i++){
    //     dp[i][0]=true;
    // }
    // dp[0][a[0]]=true;
    // for(int i=1;i<a.size();i++){
    //     for(int j=1;j<=sum;j++){
    //         bool notTake = dp[i-1][j];
    //         bool take =false;
    //         if(j>=a[i]){
    //             take = dp[j-1][j-a[i]];
    //         }
    //         dp[i][j]= (notTake||take);
    //     }
    // }
    // return dp[a.size()-1][sum];


    /*Space Optimisation*///TC= n*sum SC = n*sum
    vector<bool> d(sum+1,false);
        d[0]=true;
    if(a[0]<=sum) d[a[0]]=true;
    for(int i=1;i<a.size();i++){
        vector<bool> temp(sum+1,false);
        temp[0]=true;
        for(int j=1;j<=sum;j++){
            bool notTake = d[j];
            bool take =false;
            if(j>=a[i]){
                take = d[j-a[i]];
            }
            temp[j]= (notTake||take);
        }
        d=temp;
    }
    return d[sum];

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
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    bool val = f(a,sum,n-1,dp);
    cout<<val<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int> &a,vector<int> &dp){
    //Memoisation
    // int right = INT_MAX;
    // if(n==0) return 0;
    // if(dp[n]!=-1) return dp[n];
    // int left = f(n-1,a,dp)+abs(a[n]-a[n-1]);
    // if(n>1)
    //     right = f(n-2,a,dp)+abs(a[n]-a[n-2]);
    // return min(left,right);

    //Tabularization
    // vector<int> t(n,-1);
    // t[0] = 0;
    // for(int i=1;i<n;i++){
    //     int l = t[i-1] + abs(a[i]-a[i-1]);
    //     int r = INT_MAX;
    //     if(i>1)
    //         r = t[i-2]+abs(a[i]-a[i-2]);
    //     t[i]=min(l,r);
    // }
    // return t[n-1];

    //Optimised approach
    int prev=0,prev2;
    for(int i=1;i<n;i++){
        int l = prev + abs(a[i]-a[i-1]);
        int r = INT_MAX;
        if(i>1)
            r = prev2 + abs(a[i]-a[i-2]);
        prev2 = prev;
        int curr = min(l,r);
        prev=curr;
    }
    return prev;
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n,0);
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a[i]=temp;
    }
    vector<int>dp(n,-1);
    int ans = f(n-1,a,dp);
    cout<<ans<<endl;
}
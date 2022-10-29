#include<bits/stdc++.h>

using namespace std;

int f(int idx,vector<int> &a,vector<int> &dp){
    dp[0]=a[0];
    for(int i=1;i<idx;i++){
        int pick = a[i];
        if(idx>1){
            pick+= dp[idx-1];
        }
        int notpick = dp[idx-2];
        dp[i] = max(pick,notpick);
    }

    return dp[idx];
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(n,-1);
    int val = f(n,a,dp);
    cout<<val<<endl;
}
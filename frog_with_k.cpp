#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int> a,vector<int> &dp,int k){
    if(n==0){
        return 0;
    }
    int mini = INT_MAX;
    for(int i=1;i<=k;i++){
        
        if(n>=i){
            int jump = f(n-i,a,dp,k) + abs(a[n]-a[n-i]);
            mini= min(mini,jump);
        }
        dp[i] = mini;
    }
    return dp[n];
    
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
    int k;
    cin>>k;
    vector<int>dp(n,-1);
    int ans = f(n-1,a,dp,k);
    cout<<ans<<endl;
}
#include<bits/stdc++.h>
using namespace std;

bool f(vector<int> &a,int sum){
        vector<bool> dp(sum+1,false);
        dp[0]=true;
        if(sum>=a[0]) dp[a[0]]=true;
        for(int i=1;i<a.size();i++){
            vector<bool> temp(sum+1,false);
            temp[0]=true;
            for(int j=1;j<=sum;j++){
                bool notTake = dp[j];
                bool take =false;
                if(j>=a[i]) take = dp[j-a[i]];
                temp[j]= (take||notTake);
            }
            dp=temp;
        }
        return dp[sum];
        
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        if(sum%2!=0) return false;
        int val= sum/2;
        if(f(nums,val)){
            return true;
        }
        return false;
        
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
    bool val = canPartition(a);
    cout<<val<<endl;
}
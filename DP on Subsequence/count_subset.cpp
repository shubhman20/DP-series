#include<bits/stdc++.h>
using namespace std;

int f(int idx,vector<int>& arr,int sum,vector<vector<int>>&dp){
    /*Recurrsive approach*/ //TC= 2*n ; SC = n
    // if(sum==0) return 1;
	//     if(idx==0){
	//         if(arr[0]==sum) return 1;
	//         else
	//             return 0;
	//     }
	//     int notPick = f(idx-1,arr,sum);
	//     int pick =0;
	//     if(arr[idx]<=sum){
	//         pick=f(idx-1,arr,sum-arr[idx]);
	//     }
	//     return pick+notPick;

    /*Memoisation*///TC=N*sum; SC = n*sum+n
    // if(sum==0) return 1;
	//     if(idx==0){
	//         if(arr[0]==sum) return 1;
	//         else
	//             return 0;
	//     }
	//     if(dp[idx][sum]!=-1) return dp[idx][sum];
	//     int notPick = f(idx-1,arr,sum,dp);
	//     int pick =0;
	//     if(arr[idx]<=sum){
	//         pick=f(idx-1,arr,sum-arr[idx],dp);
	//     }
	//     return dp[idx][sum]=pick+notPick;

    /*Tabulation*/ //TC = n*sum ; SC = n*sum
	// int n = arr.size();

    // vector<vector<int>> d(n,vector<int>(sum+1,0));
    
    // for(int i=0; i<n; i++){
    //     d[i][0] = 1;
    // }
    
    // if(arr[0]<=sum)
    //     d[0][arr[0]] = 1;
    
    // for(int ind = 1; ind<n; ind++){
    //     for(int target= 1; target<=sum; target++){
            
    //         int notTaken = d[ind-1][target];
    
    //         int taken = 0;
    //             if(arr[ind]<=target)
    //                 taken = d[ind-1][target-arr[ind]];
        
    //         d[ind][target]= notTaken + taken;
    //     }
    // }
    
    // return d[n-1][sum];

	/*Space optimisation*///TC = n*sum; SC = sum
	int n = arr.size();

    vector<int> d(sum+1,0);
        d[0] = 1;
    
    if(arr[0]<=sum)
        d[arr[0]] = 1;
    
    for(int ind = 1; ind<n; ind++){
		vector<int> curr(sum+1,0);
		curr[0]=1;
        for(int target= 1; target<=sum; target++){
            
            int notTaken = d[target];
    
            int taken = 0;
                if(arr[ind]<=target)
                    taken = d[target-arr[ind]];
        
            curr[target]= notTaken + taken;
        }
		d=curr;
    }
    
    return d[sum];
    

}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int cnt=0;
    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
    cnt=f(n-1,arr,sum,dp);
    cout<<cnt<<endl;
}
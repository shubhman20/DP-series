#include<bits/stdc++.h>
using namespace std;

int f(int n){
    //Recurssion
    // if(n==0||n==1) return 1; //if idx is 1 or 0 then there is only one way we can go to our destination
    // int left = climbStairs(n-1); //left recursion
    // int right = climbStairs(n-2); //right recursion
    // return left+right; //total number of way
    //Base case//DP
    if(n<0) return 0;
    int a[100];
    a[0]=1;
    a[1]=2;
    for(int i=2;i<n;i++){
        a[i]=a[i-1]+a[i-2];
    }
    return a[n-1];
}

int main(){
    int n;
    cin>>n;
    int ways = f(n); //counting number of ways that it can go to n
    cout<<ways<<endl;
}
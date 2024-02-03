#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

ll solve(int i,int sum,int &target,int &n,vector<vector<ll>> &dp){
    if(target%2 == 1) return 0;
    if(sum==target/2) return 1;
    if(i>n) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    ll take= solve(i+1,sum+i,target,n,dp)%M;
    ll nottake= solve(i+1,sum,target,n,dp)%M;
    return dp[i][sum] = (take + nottake)%M;
}

int main(){
    int n;
    cin>>n;
    
    int target= (n*(n+1))/2;    
    vector<vector<ll>> dp(n+1,vector<ll>(target+1,-1));
    ll ans= solve(1,0,target,n,dp)%M;

    // jab bhi modular perform ke baad divide karna hota hai toh always do...
    // multiply it by Modular Inverse of Number which u want to divide(2 ie 500000004 in this case)
    cout<<(ans*(500000004*1LL))%M<<endl;

    return 0;
}

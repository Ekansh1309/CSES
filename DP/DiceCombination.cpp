#define ll long long
#include<bits/stdc++.h>
using namespace std;
 
int M=1e9+7;
 
ll solve(int n,vector<int> &dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=0;
    for(int i=1;i<=6;i++){
        ans=( (ans%M) + (solve(n-i,dp)%M) )%M;
    }
    return dp[n]=ans%M;
}
 
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    int ans=solve(n,dp);
    cout<<ans;
    return 0;
}
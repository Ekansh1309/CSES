#define ll long long
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define M 1000000007
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
int solve(int amount,vector<int>&coins,vector<int> &dp){
    if(amount==0) return 1;
    if(amount<0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=0;
    for(int i=0;i<coins.size();i++){
        ans+= solve(amount-coins[i],coins,dp);
        ans %=M;
    }
    return dp[amount]=ans;
}


int32_t main(){
    fast
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> dp(sum+1,-1);
    cout<<solve(sum,arr,dp);

    return 0;
}
#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int temp=n;

    int ans=INT_MAX;

    while(temp>0){
        int d= temp%10;
        if(d!=0){
            ans= min(ans,1+solve(n-d,dp));
        }
        temp=temp/10;
    }
    return dp[n]=ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1,-1);
    int ans= solve(n,dp);

    cout<<ans<<endl;

    return 0;
}
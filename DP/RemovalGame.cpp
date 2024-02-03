#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

ll solve(int i,int j,int take,vector<int> &v,vector<vector<ll>> &dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans=-1;
    if(take){
        ans= max(v[i]+solve(i+1,j,0,v,dp) , v[j] + solve(i,j-1,0,v,dp) );
    }
    else{
        ans= min(solve(i+1,j,1,v,dp) , solve(i,j-1,1,v,dp) );
    }
    return dp[i][j]= ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));

    ll ans= solve(0,n-1,1,v,dp);
    cout<<ans<<endl;
    return 0;
}
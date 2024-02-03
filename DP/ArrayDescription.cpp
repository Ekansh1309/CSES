#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int solve(int i,int x,int &m,int &n,vector<int>&v,vector<vector<ll>> &dp){
    if(i>=n) return 1;
    if(dp[i][x]!=-1) return dp[i][x];

    ll ans=0;
    if(v[i]==0){
        ll ans1= solve(i+1,x,m,n,v,dp)%M;
        ll ans2=0;
        if(x-1>=1) ans2= solve(i+1,x-1,m,n,v,dp)%M;
        ll ans3=0;
        if(x+1<=m) ans3= solve(i+1,x+1,m,n,v,dp)%M;

        ans = (ans1+ans2+ans3)%M;
    }
    else{
        if( abs(v[i] - x)<=1 ){
            ans= solve(i+1,v[i],m,n,v,dp)%M;
        }
        else ans=0;
    }
    return dp[i][x]=ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    vector<vector<ll>> dp(n+1,vector<ll>(m+1,-1));

    ll ans=0;
    if(v[0]==0){
        for(int i=1;i<=m;i++){
            ans= (ans + solve(1,i,m,n,v,dp)%M)%M;
        }
    }
    else{
        ans= solve(1,v[0],m,n,v,dp)%M;
    }
    cout<<ans<<endl;

    return 0;
}
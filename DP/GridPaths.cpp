#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1}};

ll solve(vector<vector<char>> &grid,int &n,int r,int c,vector<vector<int>> &dp){
    if(r<0 || c<0 || r>=n || c>=n || grid[r][c]=='*' ) return 0;
    if(r == n-1 && c == n-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];

    grid[r][c]='*';

    ll ans=0;
    for(int i=0;i<2;i++){
        ans = (ans%M + solve(grid,n,r+dir[i][0],c+dir[i][1],dp)%M)%M;
    }

    grid[r][c]='.';

    return dp[r][c]=ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n));

    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            grid[i][j]=ch;
        }
    }

    ll ans= solve(grid,n,0,0,dp);
    cout<<ans<<endl;
    return 0;
}
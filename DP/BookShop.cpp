#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

// int solve(int i,int x,int &n,vector<int> &prices,vector<int> &pages,vector<vector<int>> &dp){
//     if(i>=n) return 0;

//     int pick=0;
//     if(prices[i]<=x){
//         pick= pages[i] + solve(i+1,x-prices[i],n,prices,pages,dp);
//     }
//     int notpick= solve(i+1,x,n,prices,pages,dp);

//     return max(pick,notpick);
// }

int main(){
    int n,x;
    cin>>n>>x;

    // vector<vector<int>> dp(n+1,vector<int>(x+1,-1));

    vector<int> prices(n);
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }

    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }

    // int ans= solve(0,x,n,prices,pages,dp);

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){

            int skip= dp[i-1][j];
            int pick= (j>= prices[i-1] ) ? pages[i-1] + dp[i-1][j-prices[i-1] ] : 0;
            dp[i][j]=max(skip,pick);
        }
    }


    cout<<dp[n][x] <<endl;
    return 0;
}
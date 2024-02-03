#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){

    int maxn=1e6+1;
    vector<vector<int>>dp(maxn,vector<int>(2));

     dp[0][0] = 1;
     dp[0][1] = 1;

     for(int i=1;i<maxn;i++){
        dp[i][0]= (2LL * dp[i-1][0] + dp[i-1][1]) % M;
        dp[i][1]= (4LL * dp[i-1][1] + dp[i-1][0]) % M;
     }

    int t;
    cin>>t;


    while(t--){
        int n;
        cin>>n;
        
        cout<< ( dp[n-1][0] + dp[n-1][1] )%M<<endl;
    }

    return 0;
}
#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    string a,b;
    cin>>a;
    cin>>b;

    int n=a.size();
    int m=b.size();

    vector<vector<int>> dp(n+1,vector<int>(m+1,1e6));

    for(int i=0;i<=n;i++){
        dp[i][0]=i;
    }

    for(int j=0;j<=m;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if( a[i-1] == b[j-1] ){
                dp[i][j]= dp[i-1][j-1];
            }
            else{
                dp[i][j]=dp[i-1][j-1]+1;
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
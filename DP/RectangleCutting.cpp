#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    int a,b;
    cin>>a>>b;

    vector<vector<int>> dp(a+1,vector<int>(b+1,1e6));

    for(int i=1;i<=a;i++){
        dp[i][1]=i-1;
    }
    for(int i=1;i<=b;i++){
        dp[1][i]=i-1;
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }
        }
    }

    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){

            // Vertical Cut
            for(int k=1;k<b;k++){
                if(j-k>=1){
                    dp[i][j]= min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
                }
            }  
            for(int k=1;k<a;k++){
                if(i-k>=1){
                    dp[i][j]= min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
            }
        }
    }

    cout<<dp[a][b]<<endl;

    return 0;
}
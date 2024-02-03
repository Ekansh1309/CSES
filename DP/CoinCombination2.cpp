#define ll long long
#include<bits/stdc++.h>
#define M 1000000007
using namespace std;

int solveMem(vector<int>&v,int i,int s,int &n,vector<vector<int>> &dp){
    if(s==0) return 1;
    if(i>=n  ||  s<0) return 0;
    if(dp[i][s]!=-1) return dp[i][s];
    int take= solveMem(v,i,s-v[i],n,dp)%M;
    int nottake= solveMem(v,i+1,s,n,dp)%M;

    return dp[i][s]= (take + nottake)%M;
}

int main() {
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;

  vector<vector<int>> dp(n+1,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0) {
	    (dp[i][j] += dp[i][left]) %= M;
      }
    }
  }
  cout << dp[n][target] << endl;
}
#include<bits/stdc++.h>
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
const int INF = 1e18;
using namespace std;

int solve(int i,int &n,vector<vector<int>> &v,vector<int> &startTime,vector<int> &dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    auto idx= upper_bound(startTime.begin(),startTime.end(),v[i][1]) - startTime.begin();

    int taken=0,notTaken=0;
    taken= v[i][2] + solve(idx,n,v,startTime,dp);
    notTaken= solve(i+1,n,v,startTime,dp);

    return dp[i] = max(taken,notTaken);
}


int32_t main(){
    fast
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(3,0));
    vector<int> startTime(n);

    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[i][0]=a;
        v[i][1]=b;
        v[i][2]=c;

        startTime[i]=a;
    }

    auto cmp=[&](auto &vec1,auto &vec2){
        return vec1[0]<vec2[0];
    };

    sort(startTime.begin(),startTime.end());
    sort(v.begin(),v.end(),cmp);
    vector<int> dp(n+1,-1);

    int ans= solve(0,n,v,startTime,dp);

    cout<<ans<<endl;

    return 0;
}

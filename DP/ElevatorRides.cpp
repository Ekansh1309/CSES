#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> weight(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    vector<pair<int,int>> dp(1<<n,{1e9,1e9});

    dp[0]={1,0};

    for(int mask=1; mask<(1<<n); mask++){
        for(int bit=0; bit<n; bit++){
            if((1<<bit)&mask){
                int space=dp[mask^(1<<bit)].second;
                if(space + weight[bit]<=x){
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first, space+weight[bit]} );
                }
                else{
                    dp[mask] = min(dp[mask], {dp[mask^(1<<bit)].first+1,weight[bit]} );
                }
            }
        }
    }
    cout<<dp[(1<<n)-1].first;

    return 0;
}
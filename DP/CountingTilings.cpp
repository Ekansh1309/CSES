#include<bits/stdc++.h>

#define ll long long
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x

using namespace std;

int dp[1001][1<<11];

void generate_next_masks(int current_mask,int row,int next_mask,int n,vector<int>&next_masks){
    if(row==n+1){
        next_masks.push_back(next_mask);
        return;
    }

    if( (current_mask & (1<<row)) != 0 ){
        generate_next_masks(current_mask,row+1,next_mask,n,next_masks);
    }

    if(row != n && (current_mask & (1 << row)) == 0 && (current_mask & (1 << (row+1))) == 0 ){
        generate_next_masks(current_mask,row+2,next_mask,n,next_masks);
    }
    // current mask ke row ka value
    if( (current_mask & (1<<row)) == 0 ){
        generate_next_masks(current_mask,row+1,next_mask+(1<<row),n,next_masks);
    }

}

int solve(int col,int mask,int m,int n){
    if(col==m+1) return (mask==0) ? 1 : 0;

    if(dp[col][mask]!=-1) return dp[col][mask];
    int ans=0;
    vector<int> next_masks;
    generate_next_masks(mask,1,0,n,next_masks);

    for(auto next_mask:next_masks){
        ans= (ans+ solve(col+1,next_mask,m,n))%M;
    }
    return dp[col][mask] = ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    memset(dp,-1, sizeof(dp) );
    int ans= solve(1,0,m,n);
    cout<<ans<<endl;

    return 0;
}
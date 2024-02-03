#include<bits/stdc++.h>
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int INF = 1e18;
using namespace std;

int dp[19][2][2][11][2];

int Count(int i,bool tight1,bool tight2,int x,string &num1,string &num2,int leading_zeroes){
    if(i>=num2.size()){
        return 1;
    }

    if(x!=-1  &&  dp[i][tight1][tight2][x][leading_zeroes]!=-1){
        return dp[i][tight1][tight2][x][leading_zeroes];
    }

    int lo= (tight1) ? num1[i]-'0' : 0;
    int hi= (tight2) ? num2[i]-'0' : 9;

    int cnt=0;

    for(int idx=lo;idx<=hi;idx++){
        if(idx != x  ||  !leading_zeroes){
            cnt = cnt + Count(i+1,tight1 & (lo==idx),tight2 & (hi==idx),idx,num1,num2,leading_zeroes | (idx>0));
        }
    }
    return dp[i][tight1][tight2][x][leading_zeroes] =  cnt;
}

int32_t main(){
    fast

    int a,b;
    cin>>a>>b;

    string num1= to_string(a);
    string num2= to_string(b);

    string extendednum1=num1;

    int n1=num1.size();
    int n2=num2.size();

    int d= n2-n1;

    while(d--){
        extendednum1= '0' + extendednum1;
    }

    memset(dp,-1,sizeof(dp));

    int ans= Count(0,1,1,-1,extendednum1,num2,0);

    cout<<ans<<endl;

    return 0;
}
#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(n==0)return 0;
    vector<int> ans;
    ans.push_back(v[0]);

    for(int i=1;i<n;i++){
        if(v[i]>ans.back()){
            ans.push_back(v[i]);
        }
        else{
            int index= lower_bound(ans.begin(),ans.end(),v[i]) - ans.begin();
            ans[index]=v[i];
        }
    }

    cout<<ans.size()<<endl;

    return 0;
}
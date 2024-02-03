#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n,0);

    for(int i=0;i<n-1;i++){
        int k;
        cin>>k;
        v[k-1]++;
    }
    int ans=-1;
    for(int i=0;i<n;i++){
        if(v[i]==0){
            ans=i+1;
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}
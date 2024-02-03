#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    ll num=0;
    ll cnt=0;

    for(int i=0;i<n;i++){
        ll k;
        cin>>k;
        if(num<k) num=k;
        else{
            cnt+= num-k;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
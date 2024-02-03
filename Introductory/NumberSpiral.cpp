#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        ll r,c;
        cin>>r>>c;
        ll ans;
        if(c>=r){
            if(c%2==0){
                ans= (c-1)*(c-1) + r;
            }
            else{
                ans= c*c - r + 1;
            }
        }
        else{
            if(r%2==0){
                ans= r*r - c + 1;
            }
            else{
                ans= (r-1)*(r-1) + c;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
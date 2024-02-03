#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    for(ll n=1;n<=num;n++){
    ll ways= ( (n*n) * ((n*n)-1))/2  -  4*(n-1)*(n-2);
    cout<<ways<<endl;
    }
    return 0;
}
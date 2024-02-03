#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n>=2 && n<=3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }
    // if()

    // vector<int> v;
    for(int i=2;i<=n;i+=2){
        // v.push_back(i);
        cout<<i<<" ";
    }
    for(int i=1;i<=n;i+=2){
        // v.push_back(i);
        cout<<i<<" ";
    }

    return 0;
}

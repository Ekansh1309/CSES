#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();

    int maxlen=-1,len=-1;
    char ch='Z';
    for(int i=0;i<n;i++){
        if(ch == s[i]){
            len++;
        }
        else{
            ch=s[i];
            len=1;
        }
        maxlen= max(maxlen,len);
    }

    cout<<maxlen<<endl;

    return 0;
}
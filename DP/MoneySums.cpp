#define ll long long
#define M 1000000007
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int main(){
    int n;  
    cin>>n;
    vector<int> nums(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }

    vector<int> values(sum+1,0);

    values[0]=1;

    for(int i=0;i<n;i++){
        for(int j=sum;j>=nums[i];j--){
            if(!values[j]){
                values[j]= values[j-nums[i]];
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=sum;i++){
        if(values[i]) cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=sum;i++){
        if(values[i]){
            cout<<i<<" ";
        }
    }

    return 0;
}
#define ll long long
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    unordered_map<int,set<int>> adj;

    // Adjlist
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    int cnt=0;
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);

    queue<int> q;
    q.push(1);
    visited[1]=true;
    parent[1]=0;

    bool flag=false;

    while(!q.empty()){
        int node= q.front();
        q.pop();
        if(node==n){
            flag=true;
            break;
        }
        int size= q.size();

            for(auto i: adj[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                    parent[i]=node;
                }
            }
    }

    if(flag){
        vector<int> ans;
        
        while(n!=1){
            cnt++;
            ans.push_back(n);
            n= parent[n];
        }
        ans.push_back(1);
        cnt++;

        cout<<cnt<<endl;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
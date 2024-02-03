#define ll long long
#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int cnt=0;

void DFS(int node,unordered_map<int,set<int>> &adj,vector<int> &parent,vector<bool> &visited){
    visited[node]= true;

    for(auto i: adj[node]){
        // cycle present hai
        if(visited[i]  &&  parent[node] != i){
            while(node !=i){
                ans.push_back(node);
                node= parent[node];
            }
            ans.push_back(node);
            cnt=1;
            break;
        }
        else if(!visited[i]){
            parent[i]=node;
            DFS(i,adj,parent,visited);
            if(cnt) break;
        }
    }
}

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

    vector<int> parent(n+1,-1);
    vector<bool> visited(n+1,false);

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            DFS(i,adj,parent,visited);
            if(cnt) break;
        }
    }

    if(cnt){
        int n=ans.size();
        cout<<(n+1)<<endl;
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        } cout<<ans[0]<<endl;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
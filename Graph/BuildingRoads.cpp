#define ll long long
#include<bits/stdc++.h>
using namespace std;

void DFS(int node,unordered_map<int,bool> &visited,unordered_map<int,set<int>> &adj){
    visited[node]=true;
    for(auto i: adj[node]){
        if(!visited[i]){
            DFS(i,visited,adj);
        }
    }
}

int main(){
    unordered_map<int,set<int>> adj;
    int V,E;
    cin>>V>>E;

    // Prepare AdjList
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    unordered_map<int,bool> visited;
    vector<int> comp;
    int c=0;

    // DFS
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            DFS(i,visited,adj);
            c++;
            comp.push_back(i);
        }
    }

    cout<<c-1<<endl;
    for(int i=0;i<c-1;i++){
        cout<<comp[i]<<" "<<comp[i+1]<<endl;
    }


    return 0;
}
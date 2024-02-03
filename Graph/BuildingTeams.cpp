#define ll long long
#include<bits/stdc++.h>
using namespace std;

bool BFS(int start,int n,unordered_map<int,set<int>> &adj,vector<int> &color){
    queue<int> q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto i: adj[node]){
            if(color[i]==-1){
                color[i] = !color[node];
                q.push(i);
            }
            else if(color[i] == color[node]){
                return false;
            }
        }
    }
    return true;
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

    vector<int> color(n+1,-1);
    // To check that the graph is Bipartite or not
    int flag=0;

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(BFS(i,n,adj,color)==false){
                flag=1;
                break;
            }
        }
    }

    if(flag){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=1;i<=n;i++){
            cout<<color[i]+1<<" ";
        }
    }

    return 0;
}
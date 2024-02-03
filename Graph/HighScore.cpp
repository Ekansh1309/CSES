#include<bits/stdc++.h>
// #define ll long long
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
int INF = -1e18;
 
using namespace std;
 
int n,m;
vector<vector<int>> edges;
vector<int> dist;
 
 
int32_t main(){
    cin>>n>>m;
 
    dist.resize(n+1,INF);
    edges.resize(m);
    dist[1]=0;
 
    for(int i=0;i<m;i++){
        edges[i].resize(3);
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=w;
    }
 
    // n-1 times
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
 
            if(dist[u]+w > dist[v]){
                dist[v]= dist[u]+w;
            }
        }
    }

    int val1=dist[n];
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    bool flag=0;
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
 
            if(dist[u]+w > dist[v]){
                flag=1;
            }
    }
 
        if(flag){
            cout<<-1<<endl;
            return 0;
        }
 
 
    if(dist[n]==INF){
        cout<<-1<<endl;
    }
    else{
        cout<<dist[n]<<endl;
    }
    
    return 0;
}
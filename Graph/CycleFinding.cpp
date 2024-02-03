#include<bits/stdc++.h>
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
int INF = 1e18;
using namespace std;

int n,m;
vector<vector<int>> edges;
vector<int> dist;

int32_t main(){
    cin>>n>>m;
 
    dist.resize(n+1,INF);
    edges.resize(m);

    for(int i=0;i<m;i++){
        edges[i].resize(3);
        int u,v,w;
        cin>>u>>v>>w;
        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=w;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int w=edges[j][2];
 
            if(dist[u]+w <= dist[v]){
                dist[v]= dist[u]+w;
            }
        }
    }

    bool flag=0;
    vector<int> ans;
    for(int j=0;j<m;j++){
        int u=edges[j][0];
        int v=edges[j][1];
        int w=edges[j][2];
 
        if(dist[u]+w > dist[v]){
            flag=1;
            ans.push_back(v);
        }
    }
 
    if(flag){
        cout<<"YES"<<endl;
        for(auto i:ans){
           cout<<i<<" ";
        }
    }
    else{
        cout<<"NO"<<endl;
    }


    return 0;
}
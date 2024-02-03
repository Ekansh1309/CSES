#include<bits/stdc++.h>
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int INF = 1e18;

using namespace std;

int n,m;

void Dijkstras(int src,vector<vector<pair<int,int>>> &adj,vector<int> &dist){
    priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > q;
    dist[src]=0;
    // weight - node
    q.push({0,src});

    while(!q.empty()){
        pair<int,int> front= q.top();
        int weight= front.first;
        int node= front.second;

        q.pop();

        if(dist[node]<weight) continue;

        for(auto e: adj[node]){
            int v= e.first;
            int w= e.second;

            if(weight + w < dist[v]){
                dist[v]=weight+w;
                q.push({dist[v],v});
            }
        }
    }
}


int32_t main(){
    fast
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj1(n+1),adj2(n+1);
    vector<int> dist1(n+1,INF),dist2(n+1,INF);

    vector<tuple<int,int,int>> e;

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
        adj1[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }

    Dijkstras(1,adj1,dist1);
    Dijkstras(n,adj2,dist2);

    // for 1-n -> dist[1-k] + wk/2 + dist[k-n] or dist[n-k];
    int ans= INF;
    for( auto&tuple :e){
        int u, v, w;
        tie(u, v, w) = tuple;
        ans= min(ans,dist1[u]+dist2[v]+w/2);
    }
    cout<<ans<<endl;

    return 0;
}
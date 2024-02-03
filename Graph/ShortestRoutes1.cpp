#include<bits/stdc++.h>
// #define ll long long
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
#define int long long int

const int MAXD = 1e17;
using namespace std;

int n,m;
vector<vector<pair<int,int>>> adjList;
vector<int> dist;

void Dijkstras(){
    priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > q;
    dist[1]=0;
    // weight - node
    q.push({0,1});

    while(!q.empty()){
        pair<int,int> front= q.top();
        int weight= front.first;
        int node= front.second;

        q.pop();

        if(dist[node]<weight) continue;

        for(auto e: adjList[node]){
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
    cin>>n>>m;

    adjList.resize(n+1);
    dist.resize(n+1,MAXD);

    // prepare adjList
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
    }

    Dijkstras();

    for(int i=1;i<=n;i++){
		cout << dist[i] << " ";
	}

    return 0;
}
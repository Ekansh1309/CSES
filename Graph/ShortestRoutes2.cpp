#include<bits/stdc++.h>
#define int long long int
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x
int INF = 1e18;
using namespace std;

int n,m,q;
vector<vector<int>> g;


int32_t main(){
    cin>>n>>m>>q;
    g.resize(n+1);

    for(int i=0;i<=n;i++){
        g[i].resize(n+1);
    }

    // himself ka infinity nhi hoga thats why j=i+1
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			g[i][j] = g[j][i] = INF;
		}
	}

    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[u][v] = g[v][u] = min(g[u][v],c);
    }

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
            }
        }
    }
    // dist waali table banke aa gayi

    for(int i=0;i<q;i++){
        int u,v;
        cin>>u>>v;
        if(g[u][v]>=INF){
            g[u][v]=-1;
        }
        cout<<g[u][v]<<endl;
    }

    return 0;
}
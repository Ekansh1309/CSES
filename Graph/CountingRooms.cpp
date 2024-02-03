#define ll long long
#include<bits/stdc++.h>
using namespace std;

int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

void DFS(vector<vector<char>> &v,int &n,int &m,int i,int j){
    if(i<0 || j<0 || i>=n || j>=m){
        return ;
    }
    if(v[i][j]=='#') return ;
    v[i][j]='#';
    for(int k=0;k<4;k++){
        DFS(v,n,m,i+dir[k][0],j+dir[k][1]);
    }
}

int counting(vector<vector<char>> &v){
    int n=v.size();
    int m=v[0].size();
    int rooms=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='.'){
                DFS(v,n,m,i,j);
                rooms++;
            }
        }
    }
    return rooms;
}

int main(){
    int n,m;
    cin>>n>>m;
    // vector<vector<char>> v={ {'#','#','#','#','#','#','#','#'},
    //                         {'#','.','.','#','.','.','.','#'},
    //                         {'#','#','#','#','.','#','.','#'},
    //                         {'#','.','.','#','.','.','.','#'},
    //                         {'#','#','#','#','#','#','#','#'}};
    
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int ans= counting(v);
    cout<<ans<<endl;
    return 0;
}
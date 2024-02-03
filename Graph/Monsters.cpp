#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x

using namespace std;

//              D      R     U       L
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int n,m;

int sx,sy;

vector<string> grid;
vector<vector<int>> vis;


bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m || vis[x][y]==-1) return false;
    if(vis[x][y]) return false;
    return true;
}

// x,y  value
queue<pair<pair<int,int>,int>> q;

void BFS(){
    while(!q.empty()){
        int x= q.front().first.first;
        int y= q.front().first.second;
        int val= q.front().second;

        q.pop();

        // if(x==ex || y==ey) continue;

        for(int i=0;i<4;i++){
            int newx= x + dir[i][0];
            int newy= y + dir[i][1];

            if(isValid(newx,newy)){
                if(i==0){
                    q.push({{newx,newy},val+1});
                    vis[newx][newy]=val+1;
                    // path[newx][newy]='D';
                }
                else if(i==1){
                    q.push({{newx,newy},val+1});
                    vis[newx][newy]=val+1;
                    // path[newx][newy]='R';
                }
                else if(i==2){
                    q.push({{newx,newy},val+1});
                    vis[newx][newy]=val+1;
                    // path[newx][newy]='U';
                }
                else if(i==3){
                    q.push({{newx,newy},val+1});
                    vis[newx][newy]=val+1;
                    // path[newx][newy]='L';
                }
            }
        }
    }
}

vector<vector<bool>> v;
vector<vector<char>> path;
int ex,ey;

bool isPathAvailable=false;

bool isValidPath(int x,int y,int val){
    if(x<0 || x>=n || y<0 || y>=m || v[x][y] || (vis[x][y]!=0 && vis[x][y]<=val+1)) return false;
    return true;
}

void BFSPath(){
    queue<pair<pair<int,int>,int>> q1;
    q1.push({{sx,sy},1});
    // if(vis[sx][sy]>1) return;
    v[sx][sy]=1;  

    while(!q1.empty()){
        int x= q1.front().first.first;
        int y= q1.front().first.second;
        int val= q1.front().second;
        
        // cout<<x<<" "<<y<<" "<<val<<endl;

        q1.pop();

        if(x==0 || x==n-1 || y==0 || y==m-1){
            ex=x; ey=y;
            isPathAvailable=true;
            break;
        }

        for(int i=0;i<4;i++){
            int newx= x + dir[i][0];
            int newy= y + dir[i][1];

            if(isValidPath(newx,newy,val)){
                if(i==0){
                    q1.push({{newx,newy},val+1});
                    v[newx][newy]=true;
                    path[newx][newy]='D';
                }
                else if(i==1){
                    q1.push({{newx,newy},val+1});
                    v[newx][newy]=true;
                    path[newx][newy]='R';
                }
                else if(i==2){
                    q1.push({{newx,newy},val+1});
                    v[newx][newy]=true;
                    path[newx][newy]='U';
                }
                else if(i==3){
                    q1.push({{newx,newy},val+1});
                    v[newx][newy]=true;
                    path[newx][newy]='L';
                }
            }
        }
    }
}


int main(){

    cin>>n>>m;

    grid.resize(n);
    path.resize(n);
    vis.resize(n);
    v.resize(n);

    for(int i=0;i<n;i++){
        path[i].resize(m);
        vis[i].resize(m);
        v[i].resize(m);
    }

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                sx=i; sy=j;
            }
            else if(grid[i][j]=='#'){
                vis[i][j]=-1;
                v[i][j]=1;
            }
            else if(grid[i][j]=='M'){
                q.push({{i,j},1});
                vis[i][j]=1;
            }
        }
    }

    // vis waali ban jayegi
    BFS();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<vis[i][j]<<" ";
    //     }cout<<endl;
    // }

    BFSPath();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(path[i][j]){
    //             cout<<path[i][j]<<" ";
    //         }
    //         else{
    //             cout<<'*'<<" ";
    //         }
    //     }cout<<endl;
    // }

    if(!isPathAvailable){
        cout<<"NO"<<endl;
        return 0;
    }

    // grid banke aa gayi
    int x=ex,y=ey;
    string ans="";
    while(x != sx || y != sy){
        ans += path[x][y];
        if(path[x][y]=='U'){
            x+=1;
        }
        else if(path[x][y]=='D'){
            x-=1;
        }
        else if(path[x][y]=='R'){
            y-=1;
        }
        else if(path[x][y]=='L'){
            y+=1;
        }
    }

    reverse(ans.begin(),ans.end());
    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;

    return 0;
}


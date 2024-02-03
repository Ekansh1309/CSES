#include<bits/stdc++.h>
#define ll long long
#define M 1000000007
#define pb push_back
#define read(x) int x; cin >> x

using namespace std;

//              D      R     U       L
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

int n,m;

int sx,sy,ex,ey;

vector<string> grid;
vector<vector<char>> path;
vector<vector<char>> vis;

bool isValid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m) return false;
    if(vis[x][y]) return false;
    return true;
}

void BFS(){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    while(!q.empty()){
        int x= q.front().first;
        int y= q.front().second;
        q.pop();
        if(x==ex && y==ey) break;

        for(int i=0;i<4;i++){
            int newx= x + dir[i][0];
            int newy= y + dir[i][1];

            if(isValid(newx,newy)){
                if(i==0){
                    q.push({newx,newy});
                    vis[newx][newy]=true;
                    path[newx][newy]='D';
                }
                else if(i==1){
                    q.push({newx,newy});
                    vis[newx][newy]=true;
                    path[newx][newy]='R';
                }
                else if(i==2){
                    q.push({newx,newy});
                    vis[newx][newy]=true;
                    path[newx][newy]='U';
                }
                else if(i==3){
                    q.push({newx,newy});
                    vis[newx][newy]=true;
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

    for(int i=0;i<n;i++){
        path[i].resize(m);
        vis[i].resize(m);
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
                vis[i][j]=true;
            }
            else if(grid[i][j]=='B'){
                ex=i; ey=j;
            }
        }
    }

    BFS();

    if(!vis[ex][ey]){
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



/*


#define ll long long
#include<bits/stdc++.h>
using namespace std;

int n,m;

string str="";

bool isValid(int x , int y,vector<vector<char>> &v,vector<vector<bool>> &vis){
    if(x<0 || y<0 || x>=n || y>=m || v[x][y] == '#' || vis[x][y] == true) return false;
	return true;
}

bool BFS(int x,int y,vector<vector<char>> &v,vector<vector<char>> &dir,vector<vector<bool>> &vis){
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=true;

    while(!q.empty()){
        int a= q.front().first;
        int b= q.front().second;
        q.pop();

        if(v[a][b]=='B'){

            while(a!=x || b!=y){
                str+= dir[a][b];

                // left se aaya hai 
                if(dir[a][b]=='L') b++;
                else if(dir[a][b]=='R') b--;
                else if(dir[a][b]=='U') a++;
                else if(dir[a][b]=='D') a--;

            }
            
            return true;
        }

    // left
    if(isValid(a,b-1,v,vis)){
        dir[a][b-1]='L';
        vis[a][b-1]=true;
        q.push({a,b-1});
    }
    // right
    if(isValid(a,b+1,v,vis)){
        dir[a][b+1]='R';
        vis[a][b+1]=true;
        q.push({a,b+1});
    }
    // down
    if(isValid(a+1,b,v,vis)){
        dir[a+1][b]='D';
        vis[a+1][b]=true;
        q.push({a+1,b});
    }
    // Up
    if(isValid(a-1,b,v,vis)){
        dir[a-1][b]='U';
        vis[a-1][b]=true;
        q.push({a-1,b});
    }
    }
    return false;
}

int main(){
    cin>>n>>m;
    // int n=5,m=8;
    vector<vector<char>> v(n,vector<char>(m));
    vector<vector<char>> dir(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    // vector<vector<char>> v={{'#','#','#','#','#','#','#','#'},
    //                         {'#','.','A','#','.','.','.','#'},
    //                         {'#','.','#','#','.','#','B','#'},
    //                         {'#','.','.','.','.','.','.','#'},
    //                         {'#','#','#','#','#','#','#','#'},
    //                         };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            cin>>ch;
            v[i][j]=ch;
        }
    }

    int x=0,y=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='A'){
                x=i; y=j;
            }
        }
    }

    if(BFS(x,y,v,dir,vis)){
        cout<<"YES"<<endl;
        cout<<str.length()<<endl;
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<dir[i][j];
        }cout<<endl;
    }

    return 0;   
}



*/
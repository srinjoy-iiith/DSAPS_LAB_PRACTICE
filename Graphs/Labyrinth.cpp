#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int sx=-1,sy=-1,ex=-1,ey=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                sx=i;
                sy=j;
            }
            else if(grid[i][j]=='B'){
                ex=i;
                ey=j;
            }
        }
    }
    vector<vector<char>> parent(n,vector<char>(m,'N'));
    vector<vector<int>> distance(n,vector<int>(m,-1));
    vector<vector<bool>> vis(n,vector<bool>(m,false));

    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    distance[sx][sy]=0;

    while(q.size()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i-1>=0 && (grid[i-1][j]=='.' || grid[i-1][j]=='B') && !vis[i-1][j]){
            parent[i-1][j]='U';
            vis[i-1][j]=true;
            distance[i-1][j]=distance[i][j]+1;
            q.push({i-1,j});
        }   
        if(i+1<n && (grid[i+1][j]=='.' || grid[i+1][j]=='B') && !vis[i+1][j]){
            parent[i+1][j]='D';
            vis[i+1][j]=true;
            distance[i+1][j]=distance[i][j]+1;
            q.push({i+1,j});
        }
        if(j-1>=0 && (grid[i][j-1]=='.' || grid[i][j-1]=='B') && !vis[i][j-1]){
            parent[i][j-1]='L';
            vis[i][j-1]=true;
            distance[i][j-1]=distance[i][j]+1;
            q.push({i,j-1});
        }
        if(j+1<m && (grid[i][j+1]=='.' || grid[i][j+1]=='B') && !vis[i][j+1]){
            parent[i][j+1]='R';
            vis[i][j+1]=true;
            distance[i][j+1]=distance[i][j]+1;
            q.push({i,j+1});
        }    
    }
    if(parent[ex][ey]=='N') cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<distance[ex][ey]<<endl;
        int i=ex,j=ey;
        vector<char> path;
         while(i!=sx || j!=sy){
            path.push_back(parent[i][j]);
            if(parent[i][j]=='L') j=j+1;
            else if(parent[i][j]=='R') j=j-1;
            else if(parent[i][j]=='U') i=i+1;
            else i=i-1;
        }
        reverse(path.begin(),path.end());
        for(int k=0;k<path.size();k++) cout<<path[k];
        cout<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, vector<bool> &vis, vector<set<int>> &edges){
    vis[vertex]=true;
    for(auto e:edges[vertex]){
        if(vis[e]==false){
            dfs(e,vis,edges);
        }
    }
    return;
}


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
    vector<set<int>> edges(n*m);
    vector<int> vertices;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int no=i*m+j;
            if(grid[i][j]=='#') continue;
            if(i-1 >=0 && grid[i-1][j]!='#') edges[no].insert((i-1)*m+j);
            if(i+1<n && grid[i+1][j]!='#') edges[no].insert((i+1)*m+j);
            if(j-1>=0 && grid[i][j-1]!='#') edges[no].insert((i)*m+j-1);
            if(j+1<m && grid[i][j+1]!='#') edges[no].insert((i)*m+j+1);
            vertices.push_back(no);
        }
    }
    int cnt=0;
    int k=vertices.size();
    vector<bool> vis(n*m,false);
    for(int i=0;i<k;i++){
        if(vis[vertices[i]]==false){
            cnt++;
            dfs(vertices[i],vis,edges);
        }
    }
    cout<<cnt<<endl;
}
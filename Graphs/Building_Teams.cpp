#include<bits/stdc++.h>
using namespace std;

bool dfs(int v, vector<bool> &vis, vector<set<int>> &edges, vector<int> &color){
    vis[v]=true;
    for(auto e:edges[v]){
        if(vis[e] && color[v]==color[e]){
            return false;
        }
        else if(vis[e] && color[v]!=color[e]){
            continue;
        }
        else{
            if(color[v]==1){
                color[e]=2;
            }
            else{
                color[e]=1;
            }
            bool b=dfs(e,vis,edges,color);
            if(b==false) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<set<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].insert(v);
        edges[v].insert(u);
    }
    vector<int> color(n+1,0);
    bool p=true;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            color[i]=1;
            bool isp=dfs(i,vis,edges,color);
            if(isp==false){
                p=false;
                break;
            }
        }
    }
    if(p==false) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=1;i<=n;i++) cout<<color[i]<<" ";
        cout<<endl;
    }

}
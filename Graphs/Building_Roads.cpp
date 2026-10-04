#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool> &vis, vector<set<int>> &edges){
    vis[v]=true;
    for(auto e:edges[v]){
        if(!vis[e]){
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
    vector<set<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].insert(v);
        edges[v].insert(u);
    }
    vector<bool> vis(n+1,false);
    int cnt=0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            ans.push_back(i);
            dfs(i,vis,edges);
        }
    }
    cout<<cnt-1<<endl;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    cout<<endl;
}
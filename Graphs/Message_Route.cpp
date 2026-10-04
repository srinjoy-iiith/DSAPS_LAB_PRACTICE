#include<bits/stdc++.h>
using namespace std;


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
    vector<int> dis(n+1,-1);
    vector<int> parent(n+1,-1);
    dis[0]=0;
    queue<pair<int,int>> q;
    q.push({1,-1});
    vis[1]=true;
    while(q.size()>0){
        int v=q.front().first;
        int par=q.front().second;
        dis[v]=dis[par]+1;
        q.pop();
        for(auto e:edges[v]){
            if(!vis[e]){
                vis[e]=true;
                parent[e]=v;
                q.push({e,v});
            }
        }
    }
    if(vis[n]==false) cout<<"IMPOSSIBLE"<<endl;
    else{
        vector<int> path;
        cout<<dis[n]<<endl;
        int curr=n;
        while(curr!=-1){
            path.push_back(curr);
            curr=parent[curr];
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
        cout<<endl;
    }
}
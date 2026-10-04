#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool> &vis, vector<set<int>> &edges, vector<int> &parent, int &start, int &end){
    vis[v]=true;
    for(auto e: edges[v]){
        if(e==parent[v]){
            continue;
        }
        else if(!vis[e]){
            parent[e]=v;
            dfs(e,vis,edges,parent,start,end);
            if(start!=-1 || end!=-1) return;
        }
        else{
            start=v;
            end=e;
            return;
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<bool> vis(n+1,false);
    vector<int> parent(n+1,-1);
    vector<set<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].insert(v);
        edges[v].insert(u);
    }
    bool isp=false;
    int s=-1,e=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,vis,edges,parent,s,e);
            if(s!=-1 && e!=-1){
                isp=true;
                break;
            }
        }
    }
    if(isp==false) cout<<"IMPOSSIBLE"<<endl;
    else{
        int cnt=0;
        int i=s;
        vector<int> ans;
        while(i!=e){
            ans.push_back(i);
            i=parent[i];
            cnt++;
        }
        ans.push_back(i);
        ans.push_back(s);
        cnt+=2;
        cout<<cnt<<endl;
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }
}
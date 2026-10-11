#include<bits/stdc++.h>
using namespace std;
stack<int> st;
vector<int> temp;
vector<vector<int>> scc;

void dfs1(int node, vector<int> &vis, vector<set<int>> &adj){
    vis[node]=1;
    for(auto e:adj[node]){
        if(!vis[e]){
            dfs1(e,vis,adj);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<set<int>> &adj){
    vis[node]=1;
    temp.push_back(node);
    for(auto e:adj[node]){
        if(!vis[e]){
            dfs2(e,vis,adj);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<set<int>> adj(n+1);
    vector<set<int>> tadj(n+1);
    vector<int> vis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        tadj[v].insert(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i,vis,adj);
        }
    }

    for(int i=0;i<=n;i++) vis[i]=0;

    while(st.size()>0){
        int x=st.top();
        st.pop();
        if(!vis[x]){
            dfs2(x,vis,tadj);
            scc.push_back(temp);
        }
        temp.clear();
    }

    cout<<scc.size()<<endl;
    vector<int> kingdoms(n+1);
    for(int i=0;i<scc.size();i++){
        for(int j=0;j<scc[i].size();j++){
            kingdoms[scc[i][j]]=i+1;
        }
    }
    for(int i=1;i<kingdoms.size();i++){
        cout<<kingdoms[i]<<" ";
    }
    cout<<endl;
}
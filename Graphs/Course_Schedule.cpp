#include<bits/stdc++.h>
using namespace std;
stack<int> st;

bool dfs(int node, vector<set<int>> &edges, vector<int> &vis, vector<int> &pathvis){
    vis[node]=1;
    pathvis[node]=1;
    for(auto e:edges[node]){
        if(!vis[e]){
            bool b=dfs(e,edges,vis,pathvis);
            if(b) return true;
        }
        else if(pathvis[e]) return true;
    }
    pathvis[node]=0;
    st.push(node);
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<set<int>> edges(n+1);
    vector<int> vis(n+1,0);
    vector<int> pathvis(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        edges[a].insert(b);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            bool b=dfs(i,edges,vis,pathvis);
            if(b==true){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    vector<int> topo;
    while(st.size()>0){
        topo.push_back(st.top());
        st.pop();
    }
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
}
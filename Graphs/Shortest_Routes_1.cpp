#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int s, vector<vector<pair<int,int>>> &adj, vector<ll> &dist, vector<bool> &vis){
    dist[s]=0;
    priority_queue <pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,s});
    while(pq.size()>0){
        int node=pq.top().second;
        int d=pq.top().first;
        pq.pop();
        if(vis[node]) continue;
        else{
            vis[node]=true;
            for(auto e: adj[node]){
                int v=e.first;
                int wt=e.second;
                if(dist[v]>dist[node]+wt){
                    dist[v]=dist[node]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<ll> dist(n+1,LLONG_MAX);
    vector<bool> vis(n+1,false);
    dijkstra(1,adj,dist,vis);
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
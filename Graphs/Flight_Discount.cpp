#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(int s, vector<vector<pair<int,int>>> &adj, vector<vector<bool>> &vis, vector<vector<ll>> &dist){
    dist[s][0]=0;
    dist[s][1]=0;
    priority_queue <vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; // (dist,node,state)
    pq.push({0,s,0});
    pq.push({0,s,1});
    while(pq.size()>0){
        ll node=pq.top()[1];
        ll d=pq.top()[0];
        ll state=pq.top()[2];
        pq.pop();
        if(vis[node][state]) continue;
        else{
            vis[node][state]=true;
            for(auto e: adj[node]){
                int neighbour=e.first;
                int wt=e.second;
                if(state==0){
                    if(dist[neighbour][1]>d+(ll)(wt/2)){
                        dist[neighbour][1]=d+(ll)(wt/2);
                        pq.push({dist[neighbour][1],neighbour,1});
                    }
                }
                if(dist[neighbour][state]>d+wt){
                    dist[neighbour][state]=d+wt;
                    pq.push({dist[neighbour][state],neighbour,state});
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
    vector<vector<ll>> dist(n+1,vector<ll>(2,LLONG_MAX));
    vector<vector<bool>> vis(n+1,vector<bool>(2,false));

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    dijkstra(1,adj,vis,dist);
    cout<<min(dist[n][0],dist[n][1])<<endl;
}
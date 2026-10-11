#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> vis(n+1,0);
    vector<int> indeg(n+1,0);
    vector<int> outdeg(n+1,0);
    vector<vector<int>> adj(n+1);
    vector<vector<int>> tadj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        tadj[b].push_back(a);
        outdeg[a]++;
        indeg[b]++;
    }
    priority_queue<int> pq;
    for(int i=1;i<=n;i++){
        if(outdeg[i]==0){
            vis[i]=1;
            pq.push(i);
        }
    }
    vector<int> topo;
    while(pq.size()>0){
        int x=pq.top();
        pq.pop();
        topo.push_back(x);
        for(auto e: tadj[x]){
            outdeg[e]--;
            if(outdeg[e]==0 && !vis[e]){
                vis[e]=1;
                pq.push(e);
            }
        }
    }
    reverse(topo.begin(),topo.end());
    if(topo.size()!=n) cout<<"IMPOSSIBLE"<<endl;
    else{
        for(int i=0;i<topo.size();i++){
            cout<<topo[i]<<" ";
        }
        cout<<endl;
    }
}
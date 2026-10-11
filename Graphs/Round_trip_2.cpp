#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<set<int>> &edges, vector<int> &color, vector<int> &parent, int &start, int &end){
    color[node]=1;
    bool hascycle=false;
    for(auto e: edges[node]){
        if(color[e]==0){
            parent[e]=node;
            bool p=dfs(e,edges,color,parent,start,end);
            if(p==true) return true;
        }
        else if(color[e]==1){
            start=node;
            end=e;
            return true;
        } 
    }
    color[node]=2;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> color(n+1,0);
    vector<set<int>> edges(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].insert(v);
    }
    vector<int> parent(n+1,-1);
    int s=-1,e=-1;
    bool hascycle=false;
    for(int i=1;i<=n;i++){
        if(color[i]==0){
            bool b=dfs(i,edges,color,parent,s,e);
            if(b==true){
                hascycle=true;
                break;
            }    
        }
    }
    if(hascycle==false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        vector<int> ans;
        ans.push_back(e);
        int curr=s;
        while(curr!=parent[e]){
            ans.push_back(curr);
            curr=parent[curr];
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

}
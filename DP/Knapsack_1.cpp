#include<bits/stdc++.h>
using namespace std;

vector<vector<long long>> dp;

long long solve(int i, int j, int W, vector<vector<int>> &v){
    int n=v.size();
    if(i==n){
        return dp[i][j]=0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    long long ans=0;
    int wt=v[i][0];
    int val=v[i][1];
    //dont pick ith
    ans=max(ans,solve(i+1,j,W,v));
    if(j+wt<=W) ans=max(ans,val+solve(i+1,j+wt,W,v));
    return dp[i][j]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,w;
    cin>>n>>w;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        int wt,val;
        cin>>wt>>val;
        vector<int> temp={wt,val};
        v.push_back(temp);
    }
    dp.assign(n+1,vector<long long>(w+1,-1));
    long long res=solve(0,0,w,v);
    cout<<res<<endl;
}
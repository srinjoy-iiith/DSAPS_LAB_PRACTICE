#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int solve(int i, int j, vector<int> &v1, vector<int> &v2){
    int n=v1.size();
    int m=v2.size();
    if(i==n || j==m) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MIN;
    if(v1[i]==v2[j]) ans=1+solve(i+1,j+1,v1,v2);
    else{
        int a=solve(i+1,j,v1,v2);
        int b=solve(i,j+1,v1,v2);
        ans=max(a,b);
    }
    return dp[i][j]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int> v2(m);
    for(int i=0;i<n;i++) cin>>v1[i];
    for(int i=0;i<m;i++) cin>>v2[i];

    dp.assign(n+1,vector<int>(m+1,-1));
    int res=solve(0,0,v1,v2);
    cout<<res<<endl;
}
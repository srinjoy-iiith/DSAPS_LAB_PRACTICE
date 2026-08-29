#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;


int solve(int i, int j, string &a, string &b){
    int n=a.size();
    int m=b.size();
    if(i==n && j==m) return dp[i][j]=0;
    if(i==n && j<m) return dp[i][j]=m-j;
    if(i<n && j==m) return dp[i][j]=(n-i);

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MAX;
    if(a[i]==b[j]) ans=min(ans,solve(i+1,j+1,a,b));
    else {
        int p=1+solve(i+1,j+1,a,b);
        int q=1+solve(i,j+1,a,b);
        int r=1+solve(i+1,j,a,b);
        ans=min(p,min(q,r));
    }
    return dp[i][j]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a,b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();
    dp.assign(n+1,vector<int>(m+1,-1));

    int res=solve(0,0,a,b);
    cout<<res<<endl;
}
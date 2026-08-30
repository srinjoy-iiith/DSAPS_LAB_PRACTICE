#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int solve(int i, int j, string &s, string &t){
    int m=s.size();
    int n=t.size();
    if(i==m || j==n) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MIN;
    if(s[i]==t[j]) ans=max(ans,1+solve(i+1,j+1,s,t));
    else{
        int a=solve(i+1,j,s,t);
        int b=solve(i,j+1,s,t);
        ans=max(a,b);
    }
    return dp[i][j]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s,t;
    cin>>s>>t;
    int m=s.size();
    int n=t.size();

    dp.assign(m+1,vector<int>(n+1,-1));
    int res=solve(0,0,s,t);
    cout<<res<<endl;
}
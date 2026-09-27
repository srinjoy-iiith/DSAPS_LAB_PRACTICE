#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int solve(int i, int j, string &v1, string &v2){
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

    string v1,v2;
    cin>>v1>>v2;

    int n=v1.size();
    int m=v2.size();

    dp.assign(n+1,vector<int>(m+1,-1));
    int res=solve(0,0,v1,v2);
    int i=0,j=0;
    string lcs;
    while(i<n && j<m){
        if(v1[i]==v2[j] && dp[i][j]==1+dp[i+1][j+1]){
            lcs+=v1[i];
            i++,j++;
        }
        else if(dp[i][j]==dp[i+1][j]){
            i++;
        }
        else if(dp[i][j]==dp[i][j+1]){
            j++;
        }
    }
    cout<<lcs<<endl;
}
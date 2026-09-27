#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int M=1000000007;

int f(int i, int j, vector<vector<char>> &grid){
    int n=grid.size();
    if(i==n-1 && j==n-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    if(i+1<n && grid[i+1][j]!='*') ans=(ans%M+f(i+1,j,grid)%M)%M;
    if(j+1<n && grid[i][j+1]!='*') ans=(ans%M+f(i,j+1,grid)%M)%M;
    return dp[i][j]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<char>> grid(n,vector<char>(n,'.'));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*'){
        cout<<0<<endl;
        return 0;
    }
    dp.assign(n,vector<int>(n,-1));
    cout<<f(0,0,grid)<<endl;
}
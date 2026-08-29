#include<bits/stdc++.h>
using namespace std;
int M=1000000007;
vector<vector<int>> dp;

int solve(int i, long long j, int n, int k){
    if(i==n && j==k) return dp[i][j]=1;
    else if(i==n && j!=k) return dp[i][j]=0;

    if(dp[i][j]!=-1) return dp[i][j];
    int ans=(solve(i+1,j+i,n,k)%M+solve(i+1,j,n,k)%M)%M;
    return dp[i][j]=ans%M;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int sum=(n*(n+1))/2;
    if(sum%2!=0){
        cout<<0<<endl;
        return 0;
    }
    dp.assign(n+2,vector<int>(sum+1,-1));
    int res=solve(1,0,n,sum/2-n)%M;
    cout<<res<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int M=1000000007;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));
    dp[n][k]=1;
    for(int j=0;j<k;j++){
        dp[n][j]=0;
    }
    for(int i=n-1;i>=0;i--){
        vector<int> pre(k+2,0);
        pre[0]=0;
        for(int x=1;x<=k+1;x++){
            pre[x]=(pre[x-1]%M+dp[i+1][x-1]%M)%M;
        }
        for(int j=k;j>=0;j--){
            int r=min(j+a[i],k);
            int ans=(pre[r+1]-pre[j]+M)%M;
            dp[i][j]=ans;
        } 
    }
    cout<<dp[0][0]<<endl;
}
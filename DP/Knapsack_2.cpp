#include<bits/stdc++.h>
using namespace std;


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
    vector<vector<long long>> dp(n+1,vector<long long>(100001,-1));
    for(int j=0;j<100001;j++){
        if(j==0) dp[n][j]=0;
        else dp[n][j]=INT_MAX;
    }    
    for(int i=0;i<=n;i++) dp[i][0]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<100001;j++){
            int wt=v[i][0];
            int val=v[i][1];
            long long ans=INT_MAX;
            ans=min(ans,dp[i+1][j]);
            if(j-val>=0 && dp[i+1][j-val]!=INT_MAX) ans=min(ans,wt+dp[i+1][j-val]);
            dp[i][j]=ans;
        }
    }                    
    int res=INT_MIN;
    for(int j=0;j<100001;j++){
        if(dp[0][j]<=w) res=max(res,j);
    }
    cout<<res<<endl;                                                          
}
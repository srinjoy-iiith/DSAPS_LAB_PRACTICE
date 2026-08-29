#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int i, vector<int> &coins){
    int n=coins.size();
    if(i==0) return dp[i]=0;

    if(dp[i]!=-1) return dp[i];

    int ans=1000001;
    for(int j=0;j<n;j++){
        if(i-coins[j]>=0) ans=min(ans,1+solve(i-coins[j],coins));
    }
    return dp[i]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    dp.assign(x+1,-1);
    int k=solve(x,coins);
    if(k==1000001) cout<<-1<<endl;
    else cout<<k<<endl;
    return 0;
}

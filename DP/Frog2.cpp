#include<bits/stdc++.h>
using namespace std;
vector<int> dp;

int solve(int i, vector<int> &h, int k){
    int n=h.size();
    if(i==n-1) return dp[i]=0;
    if(dp[i]!=-1) return dp[i];

    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j<n) ans=min(ans,abs(h[i+j]-h[i])+solve(i+j,h,k));
    }
    return dp[i]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp.assign(n,-1);
    int res=solve(0,h,k);
    cout<<res<<endl;
}
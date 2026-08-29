#include<bits/stdc++.h>
using namespace std;
vector<int> dp;

int solve(int i, vector<int> &h){
    int n=h.size();
    if(i==n-1) return dp[i]=0;
    if(dp[i]!=-1) return dp[i];

    int ans=INT_MAX;
    if(i+1<n) ans=min(ans,abs(h[i+1]-h[i])+solve(i+1,h)); 
    if(i+2<n) ans=min(ans, abs(h[i+2]-h[i])+solve(i+2,h));
    return dp[i]=ans;
}


int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    dp.assign(n,-1);
    int res=solve(0,h);
    cout<<res<<endl;
}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int M=1000000007;

int f(int i, int j, vector<int> &v, int m){
    int n=v.size();
    if(i==n) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=0;
    if(v[i]!=0){
        if(abs(v[i]-j)<=1) ans=f(i+1,v[i],v,m);
        else ans=0;
    }
    else{
        if(j+1<=m && j+1!=0) ans=(ans%M+f(i+1,j+1,v,m)%M)%M;
        if(j-1>=1 && j-1!=0) ans=(ans%M+f(i+1,j-1,v,m)%M)%M;
        if(j!=0) ans=(ans%M+f(i+1,j,v,m)%M)%M;
    }
    return dp[i][j]=ans%M;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int ans=0;
    dp.assign(n+1,vector<int>(m+1,-1));
    if(v[0]!=0) ans=f(1,v[0],v,m);
    else{
        for(int k=1;k<=m;k++){
            ans=(ans%M+f(1,k,v,m)%M)%M;
        }
    }
    cout<<ans<<endl;
}
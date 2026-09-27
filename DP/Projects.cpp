#include<bits/stdc++.h>
using namespace std;
vector<long long> dp;

long long f(int i, vector<vector<long long>> &v, vector<long long> &st){
    int n=v.size();
    if(i==n) return dp[i]=0;
    if(dp[i]!=-1) return dp[i];

    long long ans=INT_MIN;
    // take it
    int ind=upper_bound(st.begin(),st.end(),v[i][1])-st.begin();
    ans=max(ans,v[i][2]+f(ind,v,st));
    //leave it
    ans=max(ans,f(i+1,v,st));
    return dp[i]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<long long>> v;
    vector<long long> st(n);
    for(int i=0;i<n;i++){
        int s,e,p;
        cin>>s>>e>>p;
        st[i]=s;
        v.push_back({s,e,p});
    }
    sort(st.begin(),st.end());
    sort(v.begin(),v.end());
    dp.assign(n+1,-1);
    cout<<f(0,v,st)<<endl;
}
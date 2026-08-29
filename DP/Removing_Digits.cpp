#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(int i){
    if(i==0) return dp[i]=0;
    if(dp[i]!=-1) return dp[i];

    vector<int> d;
    int num=i;
    while(num>0){
        d.push_back(num%10);
        num=num/10;
    }
    int ans=INT_MAX;
    for(int j=0;j<d.size();j++){
        if(i-d[j]>=0 && d[j]!=0) ans=min(ans,1+solve(i-d[j]));
    }
    return dp[i]=ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    dp.assign(n+1,-1);
    int res=solve(n);
    cout<<res<<endl;

}
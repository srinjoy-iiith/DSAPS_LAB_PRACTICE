#include<bits/stdc++.h>
using namespace std;
int M=1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<long long> dp(x+1,-1);
    dp[0]=1;
    for(int i=1;i<=x;i++){
        long long ans=0;
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0) ans+=dp[i-coins[j]];
        }
        dp[i]=ans%M;
    }
    cout<<dp[x]<<endl;
}
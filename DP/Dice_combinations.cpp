#include<bits/stdc++.h>
using namespace std;
# define M 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> dp(n+1,-1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        long long ans=0;
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                ans=(ans+dp[i-j]);
                ans=ans%M;
            }
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int M=1000000007;
vector<vector<int>> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int> next(x+1,0);
    vector<int> cur(x+1,0);
    next[0]=1;
    cur[0]=1;
    for(int i=n-1;i>=0;i--){
        cur[0]=1;
        for(int j=1;j<coins[i] && j<=x;j++){
            cur[j]=next[j];
        }
        for(int j=coins[i];j<=x;j++){
            long long ans=0;
            ans+=next[j];
            ans+=cur[j-coins[i]];
            cur[j]=(ans>=M)?ans-M:ans;
        }
        swap(cur,next);
    }
    cout<<next[x]<<endl;
}
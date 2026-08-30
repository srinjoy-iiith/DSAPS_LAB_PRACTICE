#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<int> cur(x+1,0);
    vector<int> next(x+1,0);
    vector<int> price(n);
    vector<int> pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    for(int j=0;j<=x;j++) next[j]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=x;j>=0;j--){
            int ans=INT_MIN;
            ans=max(ans,next[j]);
            if(j+price[i]<=x) ans=max(ans,pages[i]+next[j+price[i]]);
            cur[j]=ans;
        }
        next=cur;
    }
    cout<<cur[0]<<endl;
}
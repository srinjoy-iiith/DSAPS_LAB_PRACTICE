#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f(int i, int j, vector<vector<int>> &points){
    int n=points.size();
    if(i==n) return dp[i][j]=0;
    if(dp[i][j]!=-1) return dp[i][j];

    int ans=INT_MIN;
    ans=max(ans,points[i][j]+f(i+1,(j+1)%3,points));
    ans=max(ans,points[i][j]+f(i+1,(j+2)%3,points));
    return dp[i][j]=ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> points;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        points.push_back({a,b,c});
    }
    dp.assign(n+1,vector<int>(3,-1));
   
    int a=f(0,0,points);
    int b=f(0,1,points);
    int c=f(0,2,points);
    int ans=max(a,max(b,c));
    cout<<ans<<endl;
}
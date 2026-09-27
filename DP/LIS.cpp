// O(N^2) Solution

// #include<bits/stdc++.h>
// using namespace std;
// vector<int> dp;

// int f(int i, vector<int> &v){
//     int n=v.size();
//     if(i==n-1) return dp[i]=1;
//     if(dp[i]!=-1) return dp[i];

//     int ans=1;
//     for(int j=i+1;j<n;j++){
//         if(v[j]>v[i]) ans=max(ans,1+f(j,v));
//     }
//     return dp[i]=ans;
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++) cin>>v[i];
//     dp.assign(n+1,-1);
//     int ans=INT_MIN;
//     for(int i=0;i<n;i++){
//         if(dp[i]!=-1) ans=max(ans,dp[i]);
//         else ans=max(ans,f(i,v));
//     }
//     cout<<ans<<endl;
// }


// O(NlogN) Solution using Binary Search


#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> temp;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    temp.push_back(v[0]);
    for(int i=1;i<n;i++){
        int ind=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
        if(ind==temp.size()) temp.push_back(v[i]);
        else temp[ind]=v[i];
    } 
    cout<<temp.size()<<endl;
}    
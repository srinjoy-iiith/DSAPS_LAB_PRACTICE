#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long> nse_l(n);
    vector<long long> nse_r(n);
    
    stack<int> st_l;
    stack<int> st_r;
    for(int i=0;i<n;i++){
        while(st_l.size()>0 && v[st_l.top()]>=v[i]) st_l.pop();
        if(st_l.size()==0) nse_l[i]=-1;
        else nse_l[i]=st_l.top();
        st_l.push(i);
    }

    for(int i=n-1;i>=0;i--){
        while(st_r.size()>0 && v[st_r.top()]>=v[i]) st_r.pop();
        if(st_r.size()==0) nse_r[i]=n;
        else nse_r[i]=st_r.top();
        st_r.push(i);
    }
    
    long long ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,(nse_r[i]-nse_l[i]-1)*v[i]);
    }
    cout<<ans<<endl;

}
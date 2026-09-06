#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b){
    if(a.second!=b.second){
        return (a.second<b.second);
    }
    return (a.first<b.first);

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end(),cmp);
    multiset<int> ends;
    for(int i=0;i<k;i++) ends.insert(0);
    int cnt=0;
    for(int i=0;i<n;i++){
        int s=v[i].first;
        int e=v[i].second;
        auto it=ends.upper_bound(s);
        if(it==ends.begin()) continue;
        it--;
        cnt++;
        ends.erase(it);
        ends.insert(e);
    }
    cout<<cnt<<endl;
}
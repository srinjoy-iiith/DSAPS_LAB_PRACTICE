#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    multiset<int> p;
    vector<int> mp(m);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        p.insert(k);
    }
    for(int i=0;i<m;i++) cin>>mp[i];

    for(int i=0;i<m;i++){
        int maxprice=mp[i];
        auto it=p.upper_bound(maxprice);
        if(it==p.begin()) cout<<-1<<endl;
        else{
            it--;
            cout<<*(it)<<endl;
            p.erase(it);
        }
    }
    cout<<endl;

}
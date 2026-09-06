#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x,n;
    cin>>x>>n;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    set<int> pos;
    multiset<int> dur;
    pos.insert(0);
    pos.insert(x);
    dur.insert(x);
    for(int i=0;i<n;i++){
        auto it=pos.lower_bound(p[i]);
        int l=*(prev(it));
        int r=*it;
        pos.insert(p[i]);
        dur.erase(dur.find(r-l));
        dur.insert(p[i]-l);
        dur.insert(r-p[i]);
        cout<<*dur.rbegin()<<" ";
    }
    cout<<endl;
}
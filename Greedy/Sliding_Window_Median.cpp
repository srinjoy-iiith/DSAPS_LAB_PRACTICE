#include<bits/stdc++.h>
using namespace std;

multiset<int> l;
multiset<int> r;

void add(int x){
    if(l.size()==0 || x<=*(l.rbegin())) l.insert(x);
    else r.insert(x);
}

void rebalance(){
    if(l.size()<r.size()){
        l.insert(*(r.begin()));
        r.erase(r.begin());
    }
    else if(l.size()>r.size()+1){
        r.insert(*l.rbegin());
        l.erase(prev(l.end()));
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int i=0;
    int j=0;
    for(j=0;j<k;j++){
        add(v[j]);
        rebalance();
    }
    while(j<n){
        int curr_med=*(l.rbegin());
        cout<<curr_med<<" ";
        if(v[i]<=curr_med){
            l.erase(l.find(v[i]));
        }
        else{
            r.erase(r.find(v[i]));
        }
        rebalance();
        i++;
        add(v[j]);
        rebalance();
        j++;
    }
    cout<<*(l.rbegin())<<endl;
}
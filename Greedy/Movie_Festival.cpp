#include<bits/stdc++.h>
using namespace std;

static bool cmp (pair<int,int> &a, pair<int,int> &b){
    if(a.second!=b.second) return a.second<b.second;
    return a.first<b.first;
}

bool isoverlap(pair<int,int> a, pair<int,int> b){
    if(a.second<=b.first || b.second<=a.first) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end(),cmp);
    int cnt=0;
    int i=0;
    while(i<n){
        int j=i+1;
        cnt++;
        while(j<n && isoverlap(v[i],v[j])) j++;
        i=j;
    }
    cout<<cnt<<endl;
}
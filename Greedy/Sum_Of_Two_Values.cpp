#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<pair<int,int>> v1;
    for(int i=0;i<n;i++){
        v1.push_back({v[i],i+1});
    }
    sort(v1.begin(),v1.end());
    int i=0,j=n-1;
    bool poss=false;
    while(i<j){
        if(v1[i].first+v1[j].first==x){
            cout<<v1[i].second<<" "<<v1[j].second<<endl;
            poss=true;
            break;
        }
        else if(v1[i].first+v1[j].first<x){
            i++;
        }
        else{
            j--;
        }
    }
    if(poss==false) cout<<"IMPOSSIBLE"<<endl;
}
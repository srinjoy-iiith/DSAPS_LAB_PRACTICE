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
    long long cnt=0;
    for(int i=1;i<n;i++){
        if(v[i]>=v[i-1]) continue;
        int move=(v[i-1]-v[i]);
        v[i]+=move;
        cnt+=move;
    }
    cout<<cnt<<endl;
}
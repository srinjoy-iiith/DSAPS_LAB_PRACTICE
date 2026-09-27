#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long maxsum=v[0];
    long long  curr_sum=v[0];
    for(int i=1;i<n;i++){
        curr_sum=max(v[i],curr_sum+v[i]);
        maxsum=max(maxsum,curr_sum);
    }
    cout<<maxsum<<endl;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long y=0;
        vector<long long> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            y+=v[i];
        }
        long long a1=v[0];
        long long curr_sum=v[0];
        for(int i=1;i<n-1;i++){
            curr_sum=max(curr_sum+v[i],v[i]);
            a1=max(a1,curr_sum);
        }
        long long a2=v[n-1];
        curr_sum=v[n-1];
        for(int i=n-2;i>0;i--){
            curr_sum=max(v[i],curr_sum+v[i]);
            a2=max(a2,curr_sum);
        }
        long long a=max(a1,a2);
        if(y>a) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
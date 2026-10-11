#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    stack<int> st;
    vector<int> nse(n);
    for(int i=0;i<n;i++){
        while(st.size()>0 && v[st.top()]>=v[i]){
            st.pop();
        }
        if(st.size()==0){
            nse[i]=0;
        }
        else{
            nse[i]=st.top()+1;
        }
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<nse[i]<<" ";
    }
    cout<<endl;
}
#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[i]={{a,b},i};
    }
    sort(v.begin(),v.end());
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> ans(n);
    int room_cnt=0;
    for(int i=0;i<n;i++){
        int pid=v[i].second;
        if(pq.size()==0){
            // No free Room
            room_cnt++;
            ans[pid]=room_cnt;
            pq.push({v[i].first.second+1,room_cnt});
        }
        else if(pq.top().first>v[i].first.first){
            // No free Room
            room_cnt++;
            ans[pid]=room_cnt;
            pq.push({v[i].first.second+1,room_cnt});
        }
        else{
            int room_id=pq.top().second;
            pq.pop();
            ans[pid]=room_id;
            pq.push({v[i].first.second+1,room_id});
        }
    }
    cout<<room_cnt<<endl;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#define ll long long
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
       
       unordered_map<int,vector<int> > buckets;

        int n=value.size();
        for(int i=0;i<n;i++){
            buckets[limit[i]].push_back(value[i]);
        }

        ll ans=0;
        for(int i=1;i<=n;i++){
            priority_queue<ll,vector<ll>,greater<ll> > pq;
            while(buckets[i].size()>0){
                ll val=buckets[i].back();
                buckets[i].pop_back();

                if(pq.size()<i){
                    ans=ans+val;
                    pq.push(val);
                }else if(pq.top()<val){
                    ans=ans-pq.top();
                    pq.pop();
                    pq.push(val);
                    ans=ans+val;
                }


            }
        }
        return ans;
    }
};
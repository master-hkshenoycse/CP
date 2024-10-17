#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll n=nums.size();
        priority_queue<ll> pq;
        for(auto e:nums){
            pq.push(e*1ll);
        }
        ll ans=0;
        while(k--){
            ll val=pq.top();
            pq.pop();
            ans=ans+val;
            pq.push((val+2)/3);
        }

        return ans;
    }
};
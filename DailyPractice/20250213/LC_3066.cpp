#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<ll,vector<ll>,greater<ll> >pq;
        for(auto e:nums){
            pq.push(e);
        }
        
        ll ans=0;
        while(pq.size()>1 and pq.top()<k){
            
            ll a=pq.top();
            pq.pop();
            
            ll b=pq.top();
            pq.pop();
            
            ans++;
            pq.push(2*a+b);
            
        }
        
        return ans;
        
    }
};
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<ll> pq;
        for(auto g:gifts){
            pq.push(g);
        }
        ll ans=0;

        while(k--){
            ll g=pq.top();
            pq.pop();

            ll rem=sqrt(g);
        
            pq.push(rem);
        }

        while(pq.size()>0){
            ans=ans+pq.top();
            pq.pop();
        }
        return ans;
    }
};
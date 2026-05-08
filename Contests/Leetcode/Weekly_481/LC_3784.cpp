#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        ll n=s.size(),tot_cost=0;
        vector<ll> cost_alpha(26,0);

        for(int i=0;i<n;i++){
            tot_cost+=cost[i];
            cost_alpha[s[i]-'a']+=cost[i];
        }

        ll ret=1e18;
        for(ll i=0;i<26;i++)
            ret=min(ret,tot_cost-cost_alpha[i]);
        
        return ret;
    }
};
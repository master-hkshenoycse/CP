#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll> p;
        
        for(ll i=0;i<=30;i++){
            if(n & (1ll<<i)){
                p.push_back(1ll<<i);
            }
        }
        
        vector<int> sol;
        ll mod=1e9+7;
        for(auto q:queries){
            ll l=q[0];
            ll r=q[1];
            ll ans=1;
            for(ll i=l;i<=r;i++){
                ans=(ans * p[i])%mod;
            }
            sol.push_back((int)ans);
        }
        
        
        
        return sol;
        
        
    }
};
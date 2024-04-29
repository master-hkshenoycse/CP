#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long minEnd(int n, int x) {
        vector<ll> powers_rem;
        for(ll i=0;i<=60;i++){
            if((x & (1ll<<i))==0){
                powers_rem.push_back(i);
            }
        }

        ll ans=x;   
        ll sz=powers_rem.size();
        for(ll i=0;i<sz;i++){
            if((n-1) & (1ll<<i)){
                ans+=(1ll<<powers_rem[i]);
            }
        }
        return ans;


    }
};
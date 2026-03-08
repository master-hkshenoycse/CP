#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        ll n=capacity.size();

        vector<ll> csum(n+1,0);
        for(ll i=1;i<=n;i++){
            csum[i]=csum[i-1]+capacity[i-1];
        }

        ll ret=0;
        map<pair<ll,ll>,ll> help;
        for(ll i=n;i>=1;i--){
            if(i+2<=n){
                help[{csum[i+1],capacity[i+2-1]}]++;
            }
            ll e=capacity[i-1];

            if(help.find({csum[i]+e,e}) != help.end()){
                ret=ret+help[{csum[i]+e,e}];
            }
        }
        return ret;
    }
};
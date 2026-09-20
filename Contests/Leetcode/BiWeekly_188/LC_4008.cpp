#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        ll n=monsters.size();
        vector<ll> extras(n+1,0);
        for(auto b:boosts)
            extras[b[0]]+=b[2],extras[b[1]+1]-=b[2];
        
        for(int i=1;i<n;i++)
            extras[i]+=extras[i-1];

        ll lo=0,hi=1e18,ret=1e18;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll curr=mid;
            ll f=1;

            for(ll i=0;i<n;i++){
                if(curr+extras[i]<monsters[i]){
                    f=0;
                    break;
                }
                curr=max(0ll,curr-monsters[i]);
            }

            if(f){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }
};
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        ll ans=0;
        for(ll i=0;i<=limit;i++){
            ll rem=n-i;
            if(rem<0){
                continue;
            }
            if(rem > 2*limit){
                continue;
            }
            
            ll x_start=max(0ll,rem*1ll-limit);
            ll x_end=min(limit*1ll,rem);
            ans=ans+max(0ll,x_end-x_start+1);
        }
        
        return ans;
    }
};
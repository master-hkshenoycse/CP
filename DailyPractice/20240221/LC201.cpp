#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_set_cnt(ll num,ll p){
        ll period=(1ll<<(p+1));
        ll num_periods=num/period;
        ll cnt=num_periods*(1ll<<p);
        ll rem=num%period;
        cnt+=max(0ll,rem-(1ll<<p)+1);
        return cnt;
    }
    int rangeBitwiseAnd(int left, int right) {
        ll ans=0;
        
        for(ll i=0;i<=32;i++){
            ll cnt=get_set_cnt(right,i);
            if(left>0){
                cnt-=get_set_cnt(left-1,i);
            }

            if(cnt==right-left+1ll){
                ans=ans+(1ll<<i);
            }
        }

        return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        ll ret=1e15,lo=0,hi=1e15;
        ll gc=__gcd(r[0],r[1]);
        ll lc=(r[0]*r[1])/gc;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll recharge_r0=mid/r[0];
            ll recharge_r1=mid/r[1];
            ll recharge_both=mid/lc;
            ll only_r0=recharge_r0-recharge_both;
            ll only_r1=recharge_r1-recharge_both;
            ll tmp_d0=max(0ll,d[0]-only_r1);
            ll tmp_d1=max(0ll,d[1]-only_r0);
            ll both_days=mid-(recharge_r0+recharge_r1-recharge_both);

            if(both_days>=tmp_d0+tmp_d1){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }
};
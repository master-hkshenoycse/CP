#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll ncr(ll n,ll r){
        if(r<0 || r>n) return 0;
        r=min(r,n-r);

        ll res=1;
        for(ll i=1;i<=r;i++)
            res= res*(n-i+1) /i;

        return res;
    }
    ll countLsEq(ll m, ll k){
        ll used=0, cnt=0;
        for(ll b=50;b>=0;b--){
            if(m & (1ll<<b)){
                cnt+=ncr(b,k-used);
                used++;
                if(used>k)
                    break;
            }
        }

        if(used==k)cnt++;
        return cnt;
    }

    long long nthSmallest(long long n, int k) {
        ll lo=0,hi=(1ll<<50),ret=(1ll<<50);
        while(hi>=lo){
            ll mid=(hi+lo)/2;
            if(countLsEq(mid,k)>=n){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }
};
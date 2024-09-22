#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_x(ll w,ll t){
        ll lo=0,hi=1e5,ret=0;
        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll lhs=w*(mid*mid+mid)/2ll;
            if(lhs<=t){
                ret=max(ret,mid);
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ret;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll lo=1,hi=1e16,ans=hi;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;
            ll red=0;

            for(auto w:workerTimes){
                red+=get_x(w,mid);
            }

            if(red>=mountainHeight){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }

        }
        return ans;
        
    }
};
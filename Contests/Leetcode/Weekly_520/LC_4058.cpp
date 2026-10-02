#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maxValue(vector<int>& nums) {
        ll n=nums.size(),gain=0,cs=0,max_cs_ev=0,max_cs_od=-1e18;
        for(ll i=1;i<=n;i++){
            if(i%2)
                cs=cs+nums[i-1];
            else
                cs=cs-nums[i-1];
            
            if(i%2)
                gain=min(gain,cs-max_cs_od),max_cs_od=max(max_cs_od,cs);
            else
                gain=min(gain,cs-max_cs_ev),max_cs_ev=max(max_cs_ev,cs);
        }

        return cs+2*abs(gain);

    }
};
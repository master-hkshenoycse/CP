#include<bits/stdc++.h>
#define ll long long
using namespace std;
class Solution {

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        ll ans=1e10,lo=1,hi=1e10;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            ll ops=0;
            for(auto e:nums){
                ll parts=(e+mid-1)/mid;
                ops=ops+parts-1;
            }

            if(ops<=maxOperations){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
};
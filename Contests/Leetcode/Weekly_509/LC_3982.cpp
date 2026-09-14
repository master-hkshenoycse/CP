#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int get_range(int n){
        int mx=-1,mi=11;
        while(n>0){
            mx=max(mx,(n%10));
            mi=min(mi,(n%10));
            n/=10;
        }
        return mx-mi;
    }
    int maxDigitRange(vector<int>& nums) {
        int ret=0,mx_rn=-1;
        for(auto e:nums){
            int curr_rn=get_range(e);
            if(mx_rn < curr_rn){
                mx_rn=curr_rn;
                ret=0;
            }

            if(mx_rn==curr_rn)
                ret=ret+e;
        }
        return ret;
    }
};
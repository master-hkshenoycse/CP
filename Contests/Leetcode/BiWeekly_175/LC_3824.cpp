#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int minimumK(vector<int>& nums) {
        ll n=nums.size();

        ll lo=1,hi=1e5,ret=1e5;

        while(hi>=lo){
            ll mid=(hi+lo)/2ll;

            ll ops=0;
            for(auto e:nums)
                ops=ops+(e+mid-1)/mid;
            
            if(ops<=mid*mid){
                ret=min(ret,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ret;
    }
};
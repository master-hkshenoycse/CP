#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_cnt_gt(vector<int> &nums,int lim){
        ll ret=0,j=0,n=nums.size();
        for(ll i=n-1;i>=0;i--){
            while(j<i and nums[i]+nums[j]<lim){
                j++;
            }

            if(j>=i){
                break;
            }
            ret=ret+i-j;

        }

        return ret;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        sort(nums.begin(),nums.end());
        return get_cnt_gt(nums,lower)-get_cnt_gt(nums,upper+1);

    }
};
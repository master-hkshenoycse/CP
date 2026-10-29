#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    ll get_num(string &s){
        ll ret=0;
        for(auto ch:s)
            ret=ret*10+(ch-'0');
        return ret;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        vector<ll> gains;
        ll s=0,n=nums.size();
        for(ll i=0;i<n;i++){
            string rev_num=to_string(nums[i]);
            sort(rev_num.begin(),rev_num.end());
            reverse(rev_num.begin(),rev_num.end());
            gains.push_back(get_num(rev_num)-nums[i]);
            s=s+nums[i];
        }

        sort(gains.begin(),gains.end());
        reverse(gains.begin(),gains.end());
        for(int i=0;i<k;i++)
            s=s+max(0ll,gains[i]);
        return s;

    }
};
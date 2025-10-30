#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll ans=0;
        ll req=n/3;

        for(ll i=n-2;i>=0 && req>0;i-=2){
            req--;
            ans=ans+nums[i];
        }

        return ans;
    }
};
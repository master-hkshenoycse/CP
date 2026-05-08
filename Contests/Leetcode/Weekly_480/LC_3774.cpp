#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ret=0;

        for(int i=0;i<k;i++)
            ret=ret+nums[n-i-1]-nums[i];

        return ret;
    }
};
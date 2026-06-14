#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        int len=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1])
                return n-len;
            len++;
        }

        return n-len;
    }
};
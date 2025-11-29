#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ret;
        int value = 0;
        for(int i=0;i<nums.size();i++){
            value = (value*2+ nums[i])%5;
            ret.push_back(value == 0);
        }

        return ret;
    }
};
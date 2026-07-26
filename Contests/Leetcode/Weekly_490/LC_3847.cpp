#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int sc_diff=0,si=1;

        for(int i=0;i<nums.size();i++){
            if(i%6==5)
                si=-1*si;
            if(nums[i]%2)
                si=-1*si;
            sc_diff+=si*nums[i];
        }
        return sc_diff;
    }
};